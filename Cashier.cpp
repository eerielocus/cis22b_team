#define _CRT_SECURE_NO_WARNINGS

#include "Cashier.h"
#include <iostream>

using namespace std;

Cashier::Cashier(BookStore* store) : Menu(store) { }

void Cashier::menu()
{
	int index[30];
	int choice, i = 0;
	string term, yesno;
	bool exit = false;

	while (!exit)
	{
		bool found = false;

		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "{ CASHIER }                " << endl << endl;
		cout << setw(25) << "Add by:       " << endl;
		cout << setw(35) << "1. [ Title ]               " << endl;
		cout << setw(35) << "2. [ ISBN ]                " << endl;
		cout << setw(35) << "3. [ Author ]              " << endl;
		cout << setw(35) << "4. [ Checkout ]            " << endl;
		cout << setw(35) << "5. [ Exit ]                " << endl << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore();

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
						cout << "Please enter title to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						cout << setw(25) << "Add to cart?: (Y/N) ";
						cin >> yesno;
						break;

					case 2: // ISBN.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ CASHIER }                " << endl << endl;
						cout << "Please enter ISBN to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						cout << setw(25) << "Add to cart?: (Y/N) ";
						cin >> yesno;
						break;

					case 3: // Author.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ CASHIER }                " << endl << endl;
						cout << "Please enter author to search: ";
						getline(cin, term);
						cin.clear();
						index[i] = store.findBook(term, choice);
						found = true;

						cout << "Found:\n" << store.get(index[i]).toString() << endl << endl;
						cout << setw(25) << "Add to cart?: (Y/N) ";
						cin >> yesno;
						break;

					case 4: // Checkout.
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ PROCEEDING TO CHECKOUT } " << endl << endl;
						exit = true;
						found = true;
						yesno = "";
						break;

					case 5: // Exit.
						return;
					}

					// If yes for adding book to cart.
					if (yesno == "Y" || yesno == "y")
					{
						// Check if it is in stock.
						if (store.get(index[i]).getQuantity() > 0)
						{
							store.get(index[i]).setQuantity(store.get(index[i]).getQuantity() - 1);
							i++; // If so, remove -1, and increment count.
						}
						else
						{
							cout << "Not in stock." << endl << endl;
							system("pause");
						}
					}
					break;
				}
				else
				{
					cout << "\n{ INVALID OPTION }\n" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					system("pause");
					break;
				}
			}
		}
		catch (char* error)
		{
			cout << error << endl << endl;
			found = false;
			cin.clear();
			system("pause");
		}
	}

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
		cout << setw(4) << store.get(index[j]).getQuantity() << setw(16) << store.get(index[j]).getISBN() << setw(30) << store.get(index[j]).getTitle() << setw(6) << "$" << store.get(index[j]).getRetailPrice() << endl;
		subtotal += store.get(index[j]).getRetailPrice();
	}

	subtax = (subtotal * .0725);
	total = (subtotal + subtax);

	cout << endl << endl;
	cout << setw(20) << "Subtotal: $" << setprecision(2) << fixed << subtotal << endl;
	cout << setw(20) << "Subtax: $" << setprecision(2) << fixed << subtax << endl;
	cout << setw(20) << "Total: $" << setprecision(2) << fixed << total << endl << endl;
	system("pause");
}