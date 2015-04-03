#include "Space.h"
#include "Player.h"
#include "Card.h"
#include "Bank.h"
#include "Board.h"
#include "moveaction.h"
#include "MoneyAction.h"
#include "GotoAction.h"
#include <QString>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <QInputDialog>
#include <QMessageBox>

using namespace std; 

Board::Board()
{
	srand(time(NULL));
    numPlayers = setNumberOfPlayers();  //Gets the number of players for the game
    playerToGo = 0;
    setTokens();
    shuffleCards();
    fillBoard();
	for (int i = 0; i < numPlayers; i++)
        allPlayers[i].addMoney(banker.withdrawFunds(2500));  //Add 2500 to each player from the banker
}

bool Board::nextPerson()
{
    if(numAlivePlayers() > 1)
    {
        shouldDie(playerToGo);
        playerToGo = (playerToGo + 1) % numPlayers;
        while(!allPlayers[playerToGo].isAlive())
            playerToGo = (playerToGo + 1) % numPlayers;

        QString info = QString("Player %1\'s Turn.").arg(playerToGo + 1);   //Rotate through the players
        QMessageBox::information(0, "Turn Information", info);

        //printConsoleBoard();
        //printStats();
        //	doAction(i);
        return true;
	}
    else
    {
        QString info = QString("Player %1 wins!").arg(findWinner() + 1);
        QMessageBox::information(0, "Turn Information", info);
        return false;
    }
}

Board::~Board()
{
	delete[] allPlayers;
	delete[] board;
}

void Board::printConsoleBoard()   //Print out the 40-square board
{
	int count = 0;
	for (int i = 0; i < 44; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i / 4 == 0 || i / 4 == 10 || j == 0 || j == 10)
			{
				if (i % 4 == 0)
					cout << "+--+";
				else if (i % 4 == 1)
				{
					printSquare(BOARD_ORDER[count], 0);
					count++;
				}
				else if (i % 4 == 2)
				{
					printSquare(BOARD_ORDER[count], 2);
					count++;
				}
				else
					cout << "+--+";
			}
			else
				cout << "    ";
		}
		cout << endl;
	}
}

void Board::shouldDie(int i)   //consider scenarios where a player is eliminated
{
	if (allPlayers[i].isAlive())
	{
        if (allPlayers[i].getMoney() <= 0)   //out of money
		{
            QString info = QString("Player %1 ran out of money.").arg(i + 1);
            QMessageBox::information(0, "Turn Information", info);
			allPlayers[i].die();
			removeProperties(i);
		}
    }
}

void Board::shouldResign()
{
    if (allPlayers[playerToGo].isAlive())   //by choice
    {
        int reply = QMessageBox::question(0, "Turn Question", "Want to resign the game?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QString info = QString("Player %1 resigned.").arg(playerToGo + 1);
            QMessageBox::information(0, "Turn Information", info);
            allPlayers[playerToGo].die();
            removeProperties(playerToGo);
        }
    }
}

void Board::selectBuyOrUpgrade()
{
    doAction(playerToGo);
}

void Board::printStats()
{
    /*
	for (int i = 0; i < numPlayers; i++)
		cout << "Player " << allPlayers[i].getToken() << ": " << allPlayers[i].getMoney() << endl;
    */
}

int Board::getNumPlayers()
{
    return numPlayers;
}

int Board::getNextPlayer()
{
    return playerToGo;
}

Player* Board::getPlayer(int i)
{
    if(i >= numPlayers)
        return NULL;
    else
        return &(allPlayers[i]);
}

Player* Board::getAllPlayers()
{
    return allPlayers;
}

void Board::roll()   //Gets the number of steps the current token needs to take
{
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int amount = die1 + die2;
    allPlayers[playerToGo].move(amount);

    QString info = QString("Rolling ... Move %1 Spaces" ).arg(amount);
    QMessageBox::information(0, "Roll Information", info);
}

int Board::setNumberOfPlayers()   //Prompts user to enter number of players between two and four
{
    int players = QInputDialog::getInt(0, "Number Of Players", "How Many Players?: ", 1);
    while (players < 2 || players > 4)
        players = QInputDialog::getInt(0, "Invalid Input", "How Many Players?: ", 1);   //bad input checking
	allPlayers = new Player[players];
	return players;
}

void Board::setTokens()   //Prompts user to enter the token representing each player
{
	for (int i = 0; i < numPlayers; i++)
    {
        QString text = QString("Enter the token Player %1 should use %2:").arg(i + 1).arg(printTokens());
        QString token = QInputDialog::getText(0, "Token Type", text);

		while (findMatch(token) || !isValidToken(token))
		{
            if (findMatch(token))
                token = QInputDialog::getText(0, "Token Already Used", text);
            else
                token = QInputDialog::getText(0, "Invalid Token", text);
		}
		allPlayers[i].setToken(token);
	}
}

bool Board::findMatch(QString tok)   //Supplementary functions for the setTokens’ checking
{
	for (int i = 0; i < numPlayers; i++)
		if (tok == allPlayers[i].getToken())
			return true;
	return false;
}

bool Board::isValidToken(QString tok)   //Supplementary functions for the setTokens’ checking
{
	for (int i = 0; i < NUM_TOKENS; i++)
		if (tok == TOKENS[i])
			return true;
	return false;
}

QString Board::printTokens()   //Print out the four tokens available for use
{
    QString str = "{";
	for (int i = 0; i < NUM_TOKENS; i++)
    {
        str += TOKENS[i];
        if(i != NUM_TOKENS - 1)
            str += ',';
    }
    str += "}";
    return str;
}

void Board::printSquare(int loc, int group)
{
    cout << loc << " " << group << endl;
}

bool Board::hasAction()
{
    return (allPlayers[playerToGo].getPosition() % 5 != 0 && board[allPlayers[playerToGo].getPosition()]->getOwner() == -1)
            || (board[allPlayers[playerToGo].getPosition()]->getOwner() == playerToGo);
}

void Board::shuffleCards()   //Shuffles the cards that would be picked up if a player land on designated spaces
{
	topCard = 0;
	for (int i = 0; i < NUM_CARDS; i++)
		cardOrder[i] = i;
	for (int i = 0; i < 10000; i++)
	{
		int first = rand() % NUM_CARDS, second = rand() % NUM_CARDS;
		int temp = cardOrder[first];
		cardOrder[first] = cardOrder[second];
		cardOrder[second] = temp;
	}
}

void Board::drawCard(Player &p)   //Prints out the action of the card being picked up
{
	Card *card = getCard(cardOrder[topCard]);
	topCard++;
	if (topCard == NUM_CARDS)
		shuffleCards();
    card->executeAction(p);   //Executes the action of the card
    QString info = card->getDescription();
    QMessageBox::information(0, "Card Information", info);
}

void Board::fillBoard()
{
	int value = 100;
	board = new Space*[40];
	for (int i = 0; i < 40; i++)
	{
		if (i % 10 == 0)
			board[i] = new Space(false, false, 0, 0, PLACE_NAMES[i]);
		else if (i % 10 == 5)
			board[i] = new Space(true, false, 0, 0, PLACE_NAMES[i]);
		else
		{
			board[i] = new Space(false, true, value, value * 3, PLACE_NAMES[i]);
			value += 50;
		}
	}
}

Card* Board::getCard(int pos)   //Sub-function of drawCard to help execute the actions from moveaction and MoneyAction
{
	switch (CARD_TYPE[pos])
	{
		case 1:	return new moveaction(CARD_DESCRIPTION[pos], CARD_VALUE[pos]);
			break;
		case 2: return new MoneyAction(CARD_DESCRIPTION[pos], CARD_VALUE[pos]);
			break;
	}
	return new GotoAction(CARD_DESCRIPTION[pos], CARD_VALUE[pos]);
}

void Board::doAutomaticActions()
{
    Space *sp = board[allPlayers[playerToGo].getPosition()];

    if (sp->canDraw())
    {
        drawCard(allPlayers[playerToGo]);
        sp = board[allPlayers[playerToGo].getPosition()];
    }

    if (sp->isPurchasable() && sp->getOwner() != playerToGo && sp->getOwner() != -1)
    {
        int amt = sp->getValue();
        if (sp->getUpgradeValue() > 0)
        {
            amt *= 0.10;
            QString info = QString("Player %1 must pay 10% rent: %2.").arg(playerToGo + 1).arg(amt);
            QMessageBox::information(0, "Bought Information", info);
        }
        else
        {
            amt *= 0.20;
            QString info = QString("Player %1 must pay 20% rent: %2.").arg(playerToGo + 1).arg(amt);
            QMessageBox::information(0, "Bought Information", info);
        }
        Card *act = new MoneyAction("rent", -1 * amt);
        Card *act2 = new MoneyAction("give", amt);
        act->executeAction(allPlayers[playerToGo]);
        act2->executeAction(allPlayers[sp->getOwner()]);
    }
}

void Board::doAction(int i)
{
	Space *sp = board[allPlayers[i].getPosition()];

	if (sp->isPurchasable())
	{
		if (sp->getOwner() == -1 && sp->getValue() < allPlayers[i].getMoney())
		{
            //Prompts user to buy an un-owned property
            QString text = QString("Would you like to purchase %1 for $ %2 ? ").arg(sp->getName().trimmed()).arg(sp->getValue());
            int resp = QMessageBox::question(0, "Property Question", text, QMessageBox::Yes|QMessageBox::No);
            if (resp == QMessageBox::Yes)
            {
				Card *act = new MoneyAction("subtract", -1 * sp->getValue());
				act->executeAction(allPlayers[i]);

                QString info = QString("Player %1 bought %2.").arg(i + 1).arg(sp->getName());
                QMessageBox::information(0, "Bought Information", info);
				sp->setOwner(i);
            }
		}
        else if (sp->getOwner() == -1)   //Checks if player has enough money
        {
            QString info = QString("Cannot Buy Property (Not Enough Money). Need: $ %1").arg(sp->getValue());
            QMessageBox::information(0, "Not Enough Money", info);
        }
		else if (sp->getOwner() == i && sp->getUpgradeValue() < allPlayers[i].getMoney())
		{
			if (sp->getUpgradeValue() > 0)
            {
                //Prompts user to upgrade his own property
                QString text = QString("Would you like to upgrade %1 for $ %2 ? ").arg(sp->getName().trimmed()).arg(sp->getValue());
                int resp = QMessageBox::question(0, "Property Question", text, QMessageBox::Yes|QMessageBox::No);
                if (resp == QMessageBox::Yes)
				{
					Card *act = new MoneyAction("subtract", -1 * sp->getUpgradeValue());
					act->executeAction(allPlayers[i]);
                    sp->setUpgradeValue(0);

                    QString info = QString("Player %1 upgraded %2.").arg(i + 1).arg(sp->getName());
                    QMessageBox::information(0, "Bought Information", info);
				}
            }
            else
                QMessageBox::information(0, "Max Upgraded", "Cannot Upgrade Any Further.");
        }
	}
}

int Board::numAlivePlayers()
{
	int count = 0;
	for (int i = 0; i < numPlayers; i++)
		if (allPlayers[i].isAlive())
			count++;
	return count;
}

int Board::findWinner()
{
	for (int i = 0; i < numPlayers; i++)
		if (allPlayers[i].isAlive())
			return i;
	return -1;
}

void Board::removeProperties(int player)
{
	int value = 100;
	for (int i = 0; i < 40; i++)
	{
		if (board[i]->getOwner() == player)
		{
			board[i]->setOwner(-1);
			board[i]->setValue(value);
            board[i]->setUpgradeValue(value * 3);
            QString info = QString("Freed up: %1").arg(board[i]->getName());
            QMessageBox::information(0, "Bought Information", info);
			value += 50;
		}
		else if (i % 10 != 0 && i % 10 != 5)
			value += 50;
	}
}
