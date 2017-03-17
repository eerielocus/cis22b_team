#define _CRT_SECURE_NO_WARNINGS

#include "Report.h"

using namespace std;
Report::Report(BookStore *store) : Menu(store)
{
}
void Report::menu()
{
	
}
void Report::inventory() //prints out inventory's info
{
	cout << "Here's the inventory:" << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << books[i].toString() << endl;
	}
}
void Report::wholesaleValue() //Sorts by Wholesale value
{
	int total = 0;
	int size;
	size = sizeof(books) + 1;
	cout << "List of all wholesale values: ";
	for (int i = 0; i < size; i++)
	{
		cout >> books[i].getTitle() >> ": " >> books[i].getWholesaleCost() << endl;
		total += books[i].getWholesaleCost();
	}
	cout << "The total wholesale value of the inventory is: " << total << endl;
}
void Report::retailValue() //Sorts by retail Value
{
	int total = 0;
	int size;
	size = sizeof(books) + 1;
	cout << "List of all retail values: ";
	for (int i = 0; i < size; i++)
	{
		cout >> books[i].getTitle() >> ": " >> books[i].getWholesaleCost() << endl;
		total += books[i].getWholesaleCost();
	}
	cout << "The total retail value of the inventory is: " << total << endl;
}
void Report::quantity()
{
	int size, jcount;
	size = sizeof(books) + 1;
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
		temp = books[size - 1 - i];
		books[size - 1 - i] = books[jcount];
		books[jcount] = temp;
		min = 999;
	}
}
void Report::cost()
{
	int size, jcount;
	size = sizeof(books) + 1;
	int min = 99999;
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
		temp = books[size - 1 - i];
		books[size - 1 - i] = books[jcount];
		books[jcount] = temp;
		min = 99999;
	}
}
void Report::age() //Oldest books first in the array
{
	int size, jcount;
	size = sizeof(books) + 1;
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
