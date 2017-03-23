#define _CRT_SECURE_NO_WARNINGS

#include "Cashier.h"
#include <iostream>

using namespace std;

/*
Cashier Module: Search by title, ISBN, or author. Will check stock, give option to add,
and list and calculate total including tax.

Pseudocode:
Main menu
	Ask user for choice
		1. Title
		2. ISBN
		3. Author
			Check stock, give option
		4. Checkout
			Calculate subtax total, tax, then total.
			Save quantity changes
		5. Exit
*/

Cashier::Cashier(BookStore* store) : Menu(store) { }

void Cashier::menu()
{
	int index[30], quant[30];
	int choice, qty, i = 0;
	string term, yesno;
	bool exit = false;

	while (!exit)
	{
		bool found = false;

		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "{ CASHIER }                " << endl << endl;
		cout << setw(25) << "Search by:    " << endl;
		cout << setw(35) << "1. [ Title ]               " << endl;
		cout << setw(35) << "2. [ ISBN ]                " << endl;
		cout << setw(35) << "3. [ Author ]              " << endl;
		cout << setw(35) << "4. [ Checkout ]            " << endl;
		cout << setw(35) << "5. [ Exit ]                " << endl << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore();

		if (cin.fail())
		{
			cerr << "\n{ INVALID OPTION }\n" << endl;
			cin.clear();
			cin.get();
			cin.ignore(1000, '\n');
			choice = 0;
		}

		try
		{
			while (!found)
			{
				if (choice > 0 && choice < 6)
				{
					system("cls");
					switch (choice)
					{
					case 1: // Title.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ CASHIER }                " << endl << endl;
						cout << "Please enter exact title to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						break;

					case 2: // ISBN.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ CASHIER }                " << endl << endl;
						cout << "Please enter exact ISBN to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						break;

					case 3: // Author.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ CASHIER }                " << endl << endl;
						cout << "Please enter exact author to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						break;

					case 4: // Checkout.
						exit = true;
						found = true;
						yesno = "";
						break;

					case 5: // Exit.
						return;
					}
				}
				else
				{
					cerr << "\n{ INVALID OPTION }\n" << endl;
					cin.clear();
					cin.get();
					choice = 0;
					found = false;
					break;
				}
			}
			// If book found and user not selected to exit. Confirm adding to cart with quantity amount.
			if (!exit && found)
			{
				cout << setw(25) << "Add to cart?: (Y/N) ";
				cin >> yesno;
				cin.clear();
				cin.ignore();
				// If yes for adding book to cart.
				if (yesno == "Y" || yesno == "y")
				{
					// Check if it is in stock.
					if (store.get(index[i]).getQuantity() > 1)
					{
						cout << setw(16) << "Quantity? (" << store.get(index[i]).getQuantity() << " in stock.): ";
						cin >> qty;

						if (cin.fail())
						{
							cout << setw(22) << "Invalid quantity." << endl << endl;
							cin.clear();
							cin.get();
							cin.ignore(1000, '\n');
						}
						else if (store.get(index[i]).getQuantity() < qty)
						{
							cout << setw(25) << "Not enough in stock." << endl << endl;
							cin.get();
							cin.ignore(1000, '\n');
						}
						else if (store.get(index[i]).getQuantity() >= qty)
						{
							store.get(index[i]).setQuantity(store.get(index[i]).getQuantity() - qty);
							quant[i] = qty;
							i++; // If so, remove -1, and increment count.
						}
					}
					else if (store.get(index[i]).getQuantity() == 1)
					{
						cout << setw(37) << "Only 1 in stock. Adding to cart." << endl << endl;
						store.get(index[i]).setQuantity(store.get(index[i]).getQuantity() - qty);
						quant[i] = 1;
						i++; // If so, remove -1, and increment count.
						cin.get();
						cin.ignore(1000, '\n');
					}
					else
					{
						cout << setw(18) << "Not in stock." << endl << endl;
						cin.get();
						cin.ignore(1000, '\n');
					}
				}
			}
		}
		catch (char* error)
		{
			cerr << error << endl << endl;
			found = false;
			cin.clear();
			cin.get();
			cin.ignore(1000, '\n');
		}
	}

	if (i > 0)
	{
		double subtotal = 0, subtax = 0, total = 0;

		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "{ CASHIER CHECKOUT}        " << endl << endl;
		cout << setw(40) << endl;
		cout << setw(40) << endl;
		cout << setw(4) << "Qty" << setw(16) << "ISBN" << setw(30) << "Title" << setw(10) << "Price" << endl;
		cout << "____________________________________________________________" << endl << endl;

		// Loop through cart and print out all items, and add to subtotal.
		for (int j = 0; j < i; j++)
		{
			cout << setw(4) << quant[j] << setw(16) << store.get(index[j]).getISBN() << setw(30) << truncate(store.get(index[j]).getTitle()) << setw(6) << "$" << store.get(index[j]).getRetailPrice() * quant[j] << endl;
			subtotal += store.get(index[j]).getRetailPrice() * quant[j];
		}

		subtax = (subtotal * .0725);
		total = (subtotal + subtax);

		cout << endl << endl;
		cout << setw(20) << "Subtotal: $" << setprecision(2) << fixed << subtotal << endl;
		cout << setw(20) << "Subtax: $" << setprecision(2) << fixed << subtax << endl;
		cout << setw(20) << "Total: $" << setprecision(2) << fixed << total << endl << endl;

		cin.get();
		cin.ignore(1000, '\n');
		store.bookWrite(); // Save quantity change to file.
	}
	else
	{
		cout << "Cart is empty. Returning the main menu." << endl;
		cin.get();
		cin.ignore(1000, '\n');
	}
}

// Simple string manipulator for long book titles.
string Cashier::truncate(string str)
{
	bool show = true;
	int width = 16;

	if (str.length() > width)
		if (show)
			return str.substr(0, width) + "...";
		else
			return str.substr(0, width);
	return str;
}