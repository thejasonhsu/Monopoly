#include "Space.h"
#include "Card.h"
#include "MoneyAction.h"

Space::Space()
{
	drawsCard = false;
	canPurchase = true;
	value = 0;
	upgradeValue = 0;
	owner = -1;
}

Space::Space(bool isDraw, bool isPurchase, int val, int upValue, QString nm)
{
	drawsCard = isDraw;
	canPurchase = isPurchase;
	value = val;
	upgradeValue = upValue;
	owner = -1;
	name = nm;
}

void Space::setValue(int val)
{
	value = val;
}

void Space::setUpgradeValue(int val)
{
	upgradeValue = val;
}

void Space::incrementValue()
{
	value += upgradeValue;
}

bool Space::isPurchasable()
{
	return canPurchase;
}

bool Space::canDraw()
{
	return drawsCard;
}

int Space::getValue()
{
	return value;
}

int Space::getUpgradeValue()
{
	return upgradeValue;
}

int Space::getOwner()
{
	return owner;
}

QString Space::getName()
{
	return name;
}

void Space::setOwner(int player)
{
	owner = player;
}
