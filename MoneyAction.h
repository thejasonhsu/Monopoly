#ifndef MONEYACTION_H
#define MONEYACTION_H

#include "Card.h"
#include "Player.h"
#include <QString>

using namespace std;

class MoneyAction : public Card					// Class creation of MoneyAction, : public Action = inherits from the class Action.
{
	public:
        MoneyAction(QString name, int amount);	// Value constructor that states money at 0, calls base class default constructor.
		int getMoney();							// Get the money.
		void executeAction(Player &p);			
};

#endif
