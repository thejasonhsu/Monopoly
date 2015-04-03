#include "Bank.h"

Bank::Bank()
{
	funds = 100000;
}

void Bank::addFunds(int value)
{
	funds += value;
}

int Bank::withdrawFunds(int value)
{
	if (funds < value)
	{
		funds = 0;
		return funds;
	}
	else
	{
		funds -= value;
		return value;
	}
}