#define _CRT_SECURE_NO_WARNINGS

#include "Report.h"

using namespace std;

Report::Report(BookStore *store) : Menu(store) { }

void Report::menu()
{
	load();
	int choice;
	bool exit = false;

	while (exit == false)
	{
		system("cls");
		cout << count;
		cout << "{ REPORT MENU }" << endl << endl;
		cout << "Select option below:" << endl;
		cout << "1. [View Inventory]" << endl;
		cout << "2. [Inventory Wholesale Value]" << endl;
		cout << "3. [Inventory Retail Value]" << endl;
		cout << "4. [Sort Inventory]" << endl;
		cout << "5. [Return to Main Menu]" << endl << endl;
		cout << "Please enter in choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore();

		if (choice > 0 && choice < 6)
		{
			switch (choice)
			{
			case 1:
				display();
				break;

			case 2:
				wholesaleValue();
				break;

			case 3:
				retailValue();
				break;

			case 4:
				cost();
				display();
				break;

			case 5:
				exit = true;
				return;
			}
		}
	}
}

void Report::display() //prints out inventory's info
{
	cout << "{ DISPLAY INVENTORY }" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << books[i].toString() << endl << "\n------------\n";
	}
	system("pause");
}

void Report::wholesaleValue() //Sorts by Wholesale value
{
	double total = 0;

	system("cls");
	cout << "{ INVENTORY WHOLESALE VALUE }" << endl << endl;
	cout << "Full list of wholesale cost:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << books[i].getTitle() << ": " << books[i].getWholesaleCost() << endl;
		total += books[i].getWholesaleCost();
	}

	cout << "\n{ TOTAL WHOLESALE VALUE OF INVENTORY }\n" << "[ $" << total << " ]\n" << endl;
	system("pause");
}

void Report::retailValue() //Sorts by retail Value
{
	double total = 0;

	system("cls");
	cout << "{ INVENTORY RETAIL VALUE }" << endl << endl;
	cout << "Full list of retail price:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << books[i].getTitle() << ": " << books[i].getRetailPrice() << endl;
		total += books[i].getRetailPrice();
	}

	cout << "\n{ TOTAL RETAIL VALUE OF INVENTORY }\n" << "[ $" << total << " ]\n" << endl;
	system("pause");
}

void Report::quantity()
{
	int jcount;
	int min = 999;
	Book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (books[j].getQuantity() < min)
			{
				min = books[j].getQuantity();
				jcount = j;
			}
		}
		temp = books[size - i];
		books[size - i] = books[jcount];
		books[jcount] = temp;
		min = 999;
	}
}

void Report::cost()
{
	int jcount;
	double min = 99999.00;
	Book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (books[j].getWholesaleCost() < min)
			{
				min = books[j].getWholesaleCost();
				jcount = j;
			}
		}
		temp = books[size - i];
		books[size - i] = books[jcount];
		books[jcount] = temp;
		min = 99999.00;
	}
}

void Report::age() //Oldest books first in the array
{
	Book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (books[j].getDate() > books[j + 1].getDate()) //Swap
			{
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}

void Report::load()
{
	for (int i = 0; i < size; i++)
	{
		books[i] = store.get(i);
		count++;
	}
}
