#ifndef BOARD_H
#define BOARD_H

#include "Space.h"
#include "Player.h"
#include "Card.h"
#include "Bank.h"
#include <QString>
#include <iostream>

using namespace std;

const QString TOKENS[] = { "dog", "thimble", "battleship", "shoe" };
const int NUM_TOKENS = 4;

const int NUM_CARDS = 5; // More to add later
const QString CARD_DESCRIPTION[] = { "MOVE FORWARD 3 SPACES", "RECEIVE 100 DOLLARS", "MOVE BACK 4 SPACES", "GO TO BEGINNING", "PAY 50 IN TAXES" };
const int CARD_VALUE[] = { 3, 100, -4, 0, -50 };
const int CARD_TYPE[] = { 1, 2, 1, 3, 2 };

const int BOARD_ORDER[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
							39, 11, 39, 11, 38, 12, 38, 12, 37, 13, 37, 13, 36, 14, 36, 14, 35,
							15, 35, 15, 34, 16, 34, 16, 33, 17, 33, 17, 32, 18, 32, 18, 31, 19,
							31, 19, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 30, 19, 29,
							28, 27, 26, 25, 24, 23, 22, 21, 20 };

const QString PLACE_NAMES[] = {	"GO",
								"Jefferson Building (JEF)",
								"Kaprielian Hall (KAP)",
								"Birnkrant Residential College (BSR)",
								"Egg Company (EGG)",
								"Chance",
								"Fluor Tower (FLT)",
								"Cardinal Gardens (CAR)",
								"Booth Hall (BMH)",
								"Fairmont Apartments (FMT)",

								"Parking Structure I",
								"Cafe 84 (KOH)",
								"Hedco Chemical Engineering (HED)",
								"Hoffman Hall (HOH)",
								"Arts and Humanities Residential College",
								"Chance",
								"Von KleinSmid Center Library (VKC)",
								"Alumni House",
								"Kerckhoff Hall (KER)",
								"King Hall (KOH)",

								"Parking Structure II",
								"Doheny Memorial Library (DML)",
								"Ground Zero Performance Cafe (TRO)",
								"Marks Hall (DXM)",
								"Webb Tower (WTO)",
								"Chance",
								"Mudd Hall (MHP)",
								"Olin Hall (OHE)",
								"Annenberg Auditorium",
								"Lyon Center (LRC)",

								"Parking Structure III",
								"Taper Hall (THH)",
								"Student Union (STU)",
								"Tutor Hall (RTH)",
								"Vivian Hall (VHE)",
								"Chance",
								"Leavey Library (LVL)",
								"International Residential College",
								"Salvatori Computer Science Center (SAL)",
								"Century Apartments (CAP)" };

class Board
{
	public:
		Board();
		~Board();

		void printConsoleBoard();
        void roll();
        void shouldResign();
        void selectBuyOrUpgrade();
        void doAutomaticActions();

        bool nextPerson();
        bool hasAction();
        int getNumPlayers();
        int getNextPlayer();

        Player* getPlayer(int i);
        Player* getAllPlayers();
		
	private:
		Space **board;
		Player *allPlayers;
		Card **deck;
		Bank banker;
        int numPlayers, topCard, playerToGo;
        int cardOrder[NUM_CARDS];

		int setNumberOfPlayers();
		void setTokens();
        bool findMatch(QString tok);
        bool isValidToken(QString tok);
        QString printTokens();
		void printSquare(int loc, int group);
		void printStats();
		void drawCard(Player &p);
		void shuffleCards();
		void fillBoard();
		Card* getCard(int pos);
		void doAction(int i);
		void shouldDie(int i);
		int numAlivePlayers();
		int findWinner();
		void removeProperties(int player);
};

#endif
