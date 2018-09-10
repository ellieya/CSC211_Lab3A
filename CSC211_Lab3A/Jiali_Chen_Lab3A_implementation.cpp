#include "Jiali_Chen_Lab3A_header.h"


pump::pump() :cpg(3.95), session_amount(0), session_cost(0), total_sold(0) {
	// Intentionally left empty
}

pump::pump(double programInput) : cpg(programInput), session_amount(0), session_cost(0), total_sold(0) {
	// Intentionally left empty
}

void pump::dispensing() {
	do {
		system("cls");

		//Information for the user: Amount dispensed and cost per gallon
		cout << "DISPENSING 0.1 GAL!\nCost per gallon: $";
		display_cpg();
		cout << '\n';

		//Increase session gas pumped & session cost
		session_amount += 0.1;
		session_cost += cpg*0.1;

		//Display current session gas pumped & session cost
		cout << "Session Totals:" << endl;
		display_amount();
		display_cost();

		//Information for the user on how to continue/quit
		cout << "\nTo continue pumping gas - Press or hold ENTER."
			<< "\nTo quit - Press any key, then press ENTER.";
		cout << '\n';

	} while (cin.get() == '\n'); //Continue loop while the user presses or holds enter

	//Add the session's amount to total sold
	total_sold += session_cost;

	//Display session information
	system("cls");
	dispense_end_message();
}

void pump::dispensing(double userInput) {
	system("cls");

	session_amount = userInput / cpg;
	session_cost = session_amount * cpg; //Used instead of userInput so that the amount is printed with dollar formatting
	total_sold += session_cost;

	dispense_end_message();
}

void pump::display_amount() {
	cout << "Amount of gas pumped: " << session_amount << endl;
}

void pump::display_cost() {
	cout << "Session cost: $" << fixed << setprecision(2) << showpoint << session_cost << endl;
}

void pump::display_cpg() {
	cout << fixed << showpoint << setprecision(2) << cpg << endl;
}

void pump::set_cpg(double progInput) {
	cpg = progInput;
}

void pump::reset() {
	session_amount = 0, session_cost = 0;
}

double pump::return_total_sold() {
	return total_sold;
}

void pump::dispense_end_message() {

	//Display final cost and message for the current session
	cout << "Session Totals (Final):" << endl;
	display_amount();
	display_cost();
	cout << "\nTHANK YOU!\nReturning to service selection...";

	//Set session gas pumped & session cost to 0 for the next customer
	reset();

	//Flush cout to allow the use of Sleep
	cout.flush();

	//Wait 7 seconds before clearing screen
	Sleep(7000);
	system("cls");
}