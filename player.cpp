#include "Player.h"
#include "Card.h"
#include "MoneyAction.h"
#include <QString>
#include <QMessageBox>

using namespace std;

Player::Player()
{
    position = 0;
    money = 0;
    token = " ";
    alive = true;
}

Player::Player(int mon, QString tok)
{
    position = 0;
    money = mon;
    token = tok;
    alive = true;
}

void Player::addMoney(int mon)
{
    money += mon;
}

void Player::setToken(QString tok)
{
    token = tok;
}

void Player::move(int spaces)
{
    if (position + spaces >= 40)
    {
        addMoney(500);
        QMessageBox::information(0, "GO! Information", "Passed GO Collect $500!");
    }
    position = (position + spaces) % 40;
}

int Player::getMoney()
{
    return money;
}

int Player::getPosition()
{
    return position;
}

QString Player::getToken()
{
    return token;
}

QChar Player::getRepresentation()
{
    QChar ch = token[0];
    return ch;
}

bool Player::isAlive()
{
    return alive;
}

void Player::die()
{
    alive = false;
}

int Player::getX()
{
    return X_POS[position];
}

int Player::getY()
{
    return Y_POS[position];
}
