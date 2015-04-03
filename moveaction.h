#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <QString>
#include "Card.h"
#include "Player.h"

using namespace std;

class moveaction : public Card					// Create a class MoveAction, : public Action = means it inherits from the class Action.
{
	public:
        moveaction(QString name, int amt);		// Constructor that will set amount to move to amt and call the base class's constructor.
		int get_amount();						// Get the value of amount.
		void executeAction(Player &p);
};

#endif
