#include "moveaction.h"
#include "Card.h"
#include <iostream>

using namespace std;

moveaction::moveaction(QString name, int amt)		// Constructor that will set amount to 0 and call the base class's name to name.
: Card(name, amt)
{

}

int moveaction::get_amount()						// Get the value of amount.
{
	return getValue();
}

void moveaction::executeAction(Player &p)
{
	p.move(getValue());								// Move the value based on the card.
}
