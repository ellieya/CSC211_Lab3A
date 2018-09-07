/*
Jiali Chen
Lab 3A - Keep on Pumping!
In Lab 3A, we use constructors and a single class to create two pump objects with different cost-per-gallon values.
Using these pump objects, we design a menu-based program that allows the user to purchase gas at self-service rate or full-service rate in 0.1 gallon intervals.
*/

#include "Jiali_Chen_Lab3A_header.h"

using namespace std;

int main() {

	int userInput;
	double priceInput;

	pump full_service;
	pump self_service(2.00);

	do {
		cout << "SELECT SERVICE:\n"
			<< "(WARNING: Invalid inputs will default to free pumping full service)\n"
			<< "Free Pumping - Dispense in 0.1 increments\n"
			<< "Price Limit - Set the maximum price you are willing to pay\n\n"
			<< "1) Full service ($3.95 per gallon) - Free Pumping \n"
			<< "2) Full service ($3.95 per gallon) - Price Limit \n"
			<< "3) Self service ($2.00 per gallon) - Free Pumping \n"
			<< "4) Self service ($2.00 per gallon) - Price Limit \n"
			<< "5) EXIT\n\n"
			<< "Input: ";
		cin >> userInput;
		cin.ignore(); //Used to ignore the \n input that proceeds
		cout << '\n';

		//Make full-service - free pumping if invalid input provided
		if (userInput < 1 || userInput > 5) {
			userInput = 1;
		}

		//Access object's dispensing method based on userInput
		switch (userInput) {
		case 1:
			full_service.dispensing();
			break;
		case 2:
			cout << "Enter maximum amount you are willing to pay: $";
			cin >> priceInput;
			full_service.dispensing(priceInput);
			break;
		case 3:
			self_service.dispensing();
			break;
		case 4:
			cout << "Enter maximum amount you are willing to pay: $";
			cin >> priceInput;
			self_service.dispensing(priceInput);
			break;
		}
	} while (userInput != 5); //End program when userInput == 5

	cout << "Total gas sold - Full-Service: $" << full_service.return_total_sold()
		<< "\nTotal gas sold - Self-Service: $" << self_service.return_total_sold() << endl;

	return 0;
}


/*
Outputs

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #1: Full Service - Free Pumping | Screen #1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 1

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #1: Full Service - Free Pumping | Screen #2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DISPENSING 0.1 GAL!
Cost per gallon: $3.95

Session Totals:
Amount of gas pumped: 10.10
Session cost: $39.90

To continue pumping gas - Press or hold ENTER.
To quit - Press any key, then press ENTER.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #1: Full Service - Free Pumping | Screen #3
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Session Totals (Final):
Amount of gas pumped: 10.10
Session cost: $39.90

THANK YOU!
Returning to service selection...


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #2: Full Service - Price Limit | Screen #1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 2

Enter maximum amount you are willing to pay: $25

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #2: Full Service - Price Limit | Screen #2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Session Totals (Final):
Amount of gas pumped: 6.32911
Session cost: $25.00

THANK YOU!
Returning to service selection...


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #3: Self Service - Free Pumping | Screen #1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 3

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #3: Self Service - Free Pumping | Screen #2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

DISPENSING 0.1 GAL!
Cost per gallon: $2.00

Session Totals:
Amount of gas pumped: 10.00
Session cost: $20.00

To continue pumping gas - Press or hold ENTER.
To quit - Press any key, then press ENTER.

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #3: Self Service - Free Pumping | Screen #3
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Session Totals (Final):
Amount of gas pumped: 10.00
Session cost: $20.00

THANK YOU!
Returning to service selection...


* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #4: Self Service - Price Limit | Screen #1
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 4

Enter maximum amount you are willing to pay: $25

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #4: Self Service - Price Limit | Screen #2
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Session Totals (Final):
Amount of gas pumped: 12.50
Session cost: $25.00

THANK YOU!
Returning to service selection...

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
RUN #5: End Screen Example
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SELECT SERVICE:
(WARNING: Invalid inputs will default to free pumping full service)
Free Pumping - Dispense in 0.1 increments
Price Limit - Set the maximum price you are willing to pay

1) Full service ($3.95 per gallon) - Free Pumping
2) Full service ($3.95 per gallon) - Price Limit
3) Self service ($2.00 per gallon) - Free Pumping
4) Self service ($2.00 per gallon) - Price Limit
5) EXIT

Input: 5

Total gas sold - Full-Service: $50.00
Total gas sold - Self-Service: $50.00
Press any key to continue . . .

*/