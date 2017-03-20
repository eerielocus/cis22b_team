#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"
#include "Report.h"
#include "Cashier.h"
#include "BookStore.h"
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/*
Main Module: Contains all calls for each module, creates BookStore with input file name passed,
provide menu options for each module and program exit.

Main menu
	Ask user for choice
		1. Cashier
		2. Inventory
		3. Report
		4. Exit
*/

int main()
{
	BookStore bookMod("Booklist.txt");		// Create list and read file and input into array.
	
	int moduleChoice;
	bool exit = false;

	while (!exit)
	{
		Inventory invMod(&bookMod);
		Report repMod(&bookMod);
		Cashier cashMod(&bookMod);

		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "1. [ Cashier ]             " << endl;
		cout << setw(35) << "2. [ Inventory ]           " << endl;
		cout << setw(35) << "3. [ Report ]              " << endl;
		cout << setw(35) << "4. [ Exit ]                " << endl << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> moduleChoice;
		if (moduleChoice < 5 && moduleChoice > 0)
		{
			
			switch (moduleChoice)
			{
			case 1:
				cashMod.menu();
				break;
			case 2:
				invMod.menu();
				break;
			case 3:
				repMod.menu();
				break;
			case 4:
				return 0;
			}
		}
		else
		{
			cout << "Incorrect output, try again.";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	system("pause");
	return 0;
}