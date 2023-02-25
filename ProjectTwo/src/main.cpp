#include <iostream>
using namespace std;

#include "SavingsAccount.h"

int main() {
	SavingsAccount savings; // create default savings account object and draw the input menu
	savings.drawInputMenu();  
	char UserIn;  // input menu prompts the user to input a value, which will be stored in this variable
	bool running = true;  // boolean value used to check if program should exit
	while (running) {
		cin >> UserIn; // get user input 
		UserIn = toupper(UserIn);  // and make the character uppercase
		if (UserIn == 'E') {  // if yes, get user inputs and update savings account object
			double Value, MonthlyIncrease, InterestRate;
			int Year;
			cout << "input new Initial Value." << endl;
			cin >> Value;
			cout << "input new Monthly Input." << endl;
			cin >> MonthlyIncrease;
			cout << "input new Interest Rate." << endl;
			cin >> InterestRate;
			cout << "input number of Years to simulate." << endl;
			cin >> Year;
			savings = SavingsAccount(Value, MonthlyIncrease, InterestRate, Year);
			savings.drawInputMenu(); //redraw input menu and restart while loops
		}
		else{
			if (UserIn == 'C') { //if yes, draw output table followed by drawing current input table again
				savings.drawOutputTables();
				savings.drawInputMenu();
			}
			else{
				if (UserIn == 'Q') { // if yes, end program
					cout << "Goodbye";
					break;
				}
				else { // else, user input an invalid character, restarts while loop
					cout << "invalid input" << endl;
					savings.drawInputMenu();
				}
			}
		}
	}
	return 0; // exit with 0
}