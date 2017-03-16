#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"
#include "BookStore.h"
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	BookStore bookMod("Booklist.txt");		// Create list and read file and input into array.
	Inventory invMod(&bookMod);				// Pass created object array reference through the Menu constructor for Inventory.

	
	int moduleChoice;
	bool flag1 = true;

	while (flag1 == true)
	{
		system("cls");
		cout << endl;
		cout << setw(35) << "Serendipty Booksellers   " << endl;
		cout << setw(35) << endl;
		cout << setw(35) << "1. to use the cash register" << endl;
		cout << setw(35) << "2. to use inventory        " << endl;
		cout << setw(35) << "3. to use reports          " << endl;
		cout << setw(35) << "4. to quit                 " << endl;
		cout << setw(35) << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> moduleChoice;
		if (moduleChoice < 5 && moduleChoice > 0)
		{
			switch (moduleChoice)
			{
			case 1:
				//CashRegister();
				break;
			case 2:
				invMod.menu();	// Testing add function.
				break;
			case 3:
				break;
			case 4:
				return 0;
			}
		}
		else
		{
			cout << "Incorrect output, try again..";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	system("pause");
	return 0;
}