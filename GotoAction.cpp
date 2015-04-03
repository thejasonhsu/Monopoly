#include "GotoAction.h"
#include "Player.h"
#include <iostream>

GotoAction::GotoAction(QString name, int amt)
: Card(name, amt)
{
	goName = name;
}

QString GotoAction::getAction()
{
	return "Card: " + goName + "\n" + "Description: " + getDescription();
}

void GotoAction::executeAction(Player &p)
{
	int loc = p.getPosition();
	p.move(getValue() - loc);			// Player needs to move a certain number of spaces = the 
										//   difference between the final location and the current location.
}
