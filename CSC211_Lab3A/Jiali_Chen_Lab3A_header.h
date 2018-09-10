#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class pump {
	double cpg; //cpg = Cost Per Gallon
	double session_amount;
	double session_cost;
	double total_sold;
	void display_amount();
		//POST: Print the amount of gas pumped
	void display_cost();
		//POST: Print the session cost
	void reset();
		//POST: Make session_amount and session_cost = 0
	void dispense_end_message();
		//POST: Print message containing session amount of gas pumped, session cost, and gratitude
public:
	pump();
		//Initialize cpg with 3.95
	pump(double);
		//cpg is initialized with programmer's argument
	void display_cpg();
		//POST: the current cpg is displayed without a dollar sign, and with at least 2 decimal points shown
	void set_cpg(double);
		//POST: Makes cpg equal to provided argument
	void dispensing();
		//A loop that dispenses 0.1 gal of gas until the user quits.
	void dispensing(double);
		//POST: Takes the user input (maximum amount willing to pay) and dispenses gas amount equal to the user input in price value
		//Not used in Lab 3A
	double return_total_sold();
		//POST: returns total_sold
		//Not used in Lab 3A
};