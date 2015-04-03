#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <QString>
#include "Player.h"

using namespace std;

class Card
{
	public:
		Card();
        Card(QString desc, int val);

        QString getDescription();
		int getValue();
		virtual void executeAction(Player &p) = 0;

	private:
        QString description;
		int value;
};

#endif
