#ifndef ACTION_H
#define ACTION_H

#include <string>

using namespace std;

class Action
{
	public:
		Action();				// Default constructor for the class.
		Action(string nm);		// Value constructor that assigns nm to name variable.
		void print_name();		// Print the name of the Action.
		string get_name();
		virtual void executeAction() = 0;
	
	private:
		string name;			// Private member name.
};

#endif