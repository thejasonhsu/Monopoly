#ifndef BANK_H
#define BANK_H

class Bank
{
	public:
		Bank();
		
		void addFunds(int value);

		int withdrawFunds(int value);

	private:
		int funds;
};

#endif