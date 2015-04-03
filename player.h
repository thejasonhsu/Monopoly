#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

using namespace std;

const int X_POS[] = {  0,  53, 105, 158, 211, 264, 317, 370, 423, 476,
                     529, 529, 529, 529, 529, 529, 529, 529, 529, 529,
                     529, 476, 423, 370, 317, 264, 211, 158, 105,  53,
                       0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

const int Y_POS[] = {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                       0,  49,  98, 147, 196, 245, 294, 343, 392, 442,
                     491, 491, 491, 491, 491, 491, 491, 491, 491, 491,
                     491, 442, 392, 343, 294, 245, 196, 147,  98,  49};

class Player
{
    public:
        Player();
        Player(int mon, QString tok);

        void addMoney(int mon);
        void setToken(QString tok);
        void die();
        void move(int spaces);

        int getMoney();
        int getPosition();
        QString getToken();
        QChar getRepresentation();
        bool isAlive();
        int getX();
        int getY();

    private:
        int money, position;
        QString token;
        bool alive;
};

#endif
