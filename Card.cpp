#include "Card.h"

Card::Card()
{
	description = "";
	value = 0;
}

Card::Card(QString desc, int val)
{
	description = desc;
	value = val;
}

QString Card::getDescription()
{
	return description;
}

int Card::getValue()
{
	return value;
}
