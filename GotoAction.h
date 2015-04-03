#ifndef GOTOACTION_H
#define GOTOACTION_H

#include "Card.h"
#include <QString>

class GotoAction : public Card
{
	public:
        GotoAction(QString name, int amt);
        QString getAction();
		void executeAction(Player &p);

	private:
        QString goName;
};

#endif
