#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"

using namespace std;

Inventory::Inventory(BookStore *store) : Menu(store) {}		// Constructor utilize referenced BookStore class and pass to Menu.

void Inventory::menu()
{
	cout << "\n\nThis ran at Inventory.\n\n";
	addBook();
}

void Inventory::addBook()
{
	Book test1("1231455", "Stuff", "Guy", "Them", 8, 5, 2016, 2, 45.32, 84.42);

	store->add(test1);	// Temporary add test example. Use pointer to Menu::store variable containing book array information and functions.
	for (int i = 0; i < 25; i++)	//Temporary print test.
	{
		Book result = store->get(i);	// Use similar pointer to get functions.
		cout << result.toString() << endl << endl;
	}

	int search = store->findBook("121455", 2);
	if (search == NULL)
		cout << "Please search again." << endl;
	else
	{
		Book searchResult = store->get(search);
		cout << searchResult.toString() << endl << endl;
	}
}

void Inventory::editBook()
{
	int choice;
	string term;
	cout << "Search for the book via: \n1. Book Title\n2. Book ISBN\n3. Book Author" << endl;
	cin >> choice;
	
	if (choice == 1)
	{
		cout << "Please enter title to search: ";
		cin >> term;
		store->findBook(term, choice);
	}
}

void Inventory::deleteBook()
{

}