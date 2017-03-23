#define _CRT_SECURE_NO_WARNINGS

#include "Report.h"

using namespace std;

/*
Report Module: Allow listing of current inventory, total of both wholesale and retail values,
and sort by quantity, age, and cost.

Pseudocode:
Main menu
	Ask user for choice
		1. Display
		2. Wholesale Value - include multiple copies
		3. Retail Value - include multiple copies
		4. Sort
			1. Quantity
				bubble sort sorting by quantity
			2. Age
				bubble sort sorting by quantity
			3. Cost
				bubble sort sorting by quantity
		5. Exit
*/

Report::Report(BookStore *store) : Menu(store) { }

void Report::menu()
{
	load();
	int choice;
	bool exit = false, exit2 = false;

	while (exit == false)
	{
		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "{ REPORT MENU }            " << endl << endl;
		cout << setw(25) << "Select option:" << endl;
		cout << setw(35) << "1. [ View Inventory ]      " << endl;
		cout << setw(35) << "2. [ Wholesale Value ]     " << endl;
		cout << setw(35) << "3. [ Retail Value ]        " << endl;
		cout << setw(35) << "4. [ Sort Inventory ]      " << endl;
		cout << setw(35) << "5. [ Return to Main Menu ] " << endl << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore();

		if (cin.fail())
		{
			cerr << "\n{ INVALID OPTION }\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			choice = 0;
			system("pause");
		}

		if (choice > 0 && choice < 6)
		{
			switch (choice)
			{
			case 1: // Show inventory.
				display();
				break;

			case 2: // List by wholesale.
				wholesaleValue();
				break;

			case 3: // List by retail.
				retailValue();
				break;

			case 4: // Select sort method.
				while (!exit2)
				{
					system("cls");
					cout << endl;
					cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
					cout << setw(35) << "{ SORT MENU }              " << endl << endl;
					cout << setw(25) << "Select option:" << endl;
					cout << setw(35) << "1. [ Quantity ]            " << endl;
					cout << setw(35) << "2. [ Wholesale Cost ]      " << endl;
					cout << setw(35) << "3. [ Date Added ]          " << endl;
					cout << setw(35) << "4. [ Return to Main Menu ] " << endl << endl;
					cout << setw(25) << "Enter choice: ";
					cin >> choice;
					cin.clear();
					cin.ignore();

					if (choice > 0 && choice < 5)
					{
						switch (choice)
						{
						case 1: // Sort by quantity.
							system("cls");
							cout << endl;
							cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
							cout << setw(35) << "{ QUANTITY (HIGH->LOW) }   " << endl << endl;
							quantity();
							display();
							break;

						case 2: // Wholesale.
							system("cls");
							cout << endl;
							cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
							cout << setw(35) << "{ WHOLESALE (HIGH->LOW) }  " << endl << endl;
							cost();
							display();
							break;

						case 3: // Age.
							system("cls");
							cout << endl;
							cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
							cout << setw(35) << "{ DATE ADDED (OLD->NEW) }  " << endl << endl;
							age();
							display();
							break;

						case 4:
							exit2 = true;
							break;
						}
					}
				}
				break;

			case 5:
				exit = true;
				return;
			}
		}
		else
		{
			cerr << "\n{ INVALID OPTION }\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			choice = 0;
		}
	}
}

// Prints out inventory's info.
void Report::display() 
{
	system("cls");
	cout << endl;
	cout << setw(35) << "{ DISPLAY INVENTORY }      " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << books[i].toString() << endl << "\n------------\n";
	}
	system("pause");
}

// List wholesale value.
void Report::wholesaleValue()
{
	double total = 0;

	system("cls");
	cout << endl;
	cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
	cout << setw(35) << "{ TOTAL WHOLESALE VALUE }  " << endl << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(40) << books[i].getTitle() << ": $" << books[i].getWholesaleCost() << " (" << books[i].getQuantity() << ")" << endl;

		if (books[i].getQuantity() == 1)
			total += books[i].getWholesaleCost();
		else if (books[i].getQuantity() > 1)
			total += books[i].getWholesaleCost() * books[i].getQuantity();
	}

	cout << endl;
	cout << setw(35) << "{ TOTAL WHOLESALE VALUE }  " << endl;
	cout << setw(18) << "[ $" << total << " ]\n" << endl;
	system("pause");
}

// List retail value.
void Report::retailValue()
{
	double total = 0;

	system("cls");
	cout << endl;
	cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
	cout << setw(35) << "{ TOTAL RETAIL VALUE }     " << endl << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(40) << books[i].getTitle() << ": $" << books[i].getRetailPrice() << " (" << books[i].getQuantity() << ")" << endl;

		if (books[i].getQuantity() == 1)
			total += books[i].getRetailPrice();
		else if (books[i].getQuantity() > 1)
			total += books[i].getRetailPrice() * books[i].getQuantity();
	}
	cout << endl;
	cout << setw(35) << "{ TOTAL WHOLESALE VALUE }  " << endl;
	cout << setw(18) << "[ $" << total << " ]\n" << endl;
	system("pause");
}

// Sort by greatest quantity first.
void Report::quantity()
{
	Book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (books[i].getQuantity() > books[j].getQuantity())
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

// Sort by greatest cost first.
void Report::cost()
{
	Book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (books[i].getWholesaleCost() > books[j].getWholesaleCost())
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

// Sort by oldest book first.
void Report::age()
{
	Book temp;

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			string tempDate1 = to_string(books[j].getYear()) + string(2 - to_string(books[j].getMonth()).length(), '0') + to_string(books[j].getMonth()) + string(2 - to_string(books[j].getDay()).length(), '0') + to_string(books[j].getDay());
			string tempDate2 = to_string(books[j + 1].getYear()) + string(2 - to_string(books[j + 1].getMonth()).length(), '0') + to_string(books[j + 1].getMonth()) + string(2 - to_string(books[j + 1].getDay()).length(), '0') + to_string(books[j + 1].getDay());
			if (tempDate1 > tempDate2)
			{
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}

// Load inventory list into temporary list.
void Report::load()
{
	for (int i = 0; i < size; i++)
		books[i] = store.get(i);
}
