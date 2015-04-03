#include <iostream>
#include "MoneyAction.h"
#include "Action.h"
#include "Player.h"
#include <QString>

using namespace std;

MoneyAction::MoneyAction(QString name, int amount)	// Value constructor that name of action & amount, calls base class value constructor.
: Card(name, amount)
{

}

int MoneyAction::getMoney()							// Get the money.
{
	return getValue();
}

void MoneyAction::executeAction(Player &p)			// Abstract Base Class executeAction() function.
{
	p.addMoney(getValue());
}
