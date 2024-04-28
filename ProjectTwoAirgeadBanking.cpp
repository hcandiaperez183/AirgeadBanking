/*
 * Haley Candia Perez
 *
 * 04/06/2024
 * 
 * ProjectTwoAirgeadBanking.cpp
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Banking.h"

using namespace std;

Banking myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
double months;
int years;
char user_input = 'a';
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();

// Main function
int main() {
	while (user_input != 'q') {
		system("cls");
		PrintHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		std::cout << "Enter 'q' to quit. To run a report, enter any other character or number. ";
		std::cin >> user_input;
	}

	return 0;
}

// Print main screen and get input from user
void PrintHomeScreen() {
	try {
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Amount of Investmentt: $";
		//cin >> initialInvestment;
		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid entry. Please try again.");
		}
		myInvestment.SetInitialInvestment(initialInvestment);
		cout << "Monthly Deposit Amount: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry. Please try again.");
		}
		myInvestment.SetMonthlyDeposit(monthlyDeposit);
		cout << "Annual Interest Amount: %";
		annualInterest = validDoubleInput();;
		if (annualInterest < 0) {
			throw runtime_error("Invalid entry. Please try again");
		}
		myInvestment.SetInterestRate(annualInterest);
		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry. Please try again.");
		}
		myInvestment.SetNumberOfYears(years);

		system("PAUSE");
	}

	// Displays error message to user and displays home screen again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Negative value not accepted." << endl;
		system("PAUSE");
		system("cls");
		PrintHomeScreen();
	}
}

// Validate user input is an integer
int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			break;
		}
		else {
			cout << "Invalid entry. Input a numerical value.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

// Validate input is a double
double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			break;
		}
		else {
			cout << "Invalid entry. Input a valid number. ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}