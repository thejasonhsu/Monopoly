#ifndef SPACE_H
#define SPACE_H

#include "Action.h"
#include <QString>

class Space
{
	public:
		Space();
        Space(bool isDraw, bool isPurchase, int val, int upValue, QString nm);

		void setValue(int val);
		void incrementValue();
		void setAction(int spaceNo);
		void setUpgradeValue(int val);
		void setOwner(int player);

		bool isPurchasable();
		bool canDraw();
		int getValue();
		int getUpgradeValue();
		int getOwner();
        QString getName();

	private:
		bool drawsCard, canPurchase;
		int value, upgradeValue, owner;
        QString name;
};

#endif
