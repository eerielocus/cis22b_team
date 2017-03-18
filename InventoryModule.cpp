#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"

using namespace std;

Inventory::Inventory(BookStore *store) : Menu(store) { }		// Constructor utilize referenced BookStore class and pass to Menu.

void Inventory::menu()
{
	int choice;
	bool exit = false;

	while (!exit)
	{
	system("cls");
	cout << store.getCount() << endl << store.getSize();
	cout << "{ INVENTORY MENU }" << endl << endl;
	cout << "Select option below:" << endl;
	cout << "1. [Search for Book]" << endl;
	cout << "2. [Add Book]" << endl;
	cout << "3. [Remove Book]" << endl;
	cout << "4. [Edit Book]" << endl;
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
				lookUpBook();
				break;

			case 2:
				addBook();
				break;

			case 3:
				deleteBook();
				break;

			case 4:
				editBook();
				break;

			case 5:
				exit = true;
				return;
			}
		}
	}
}

void Inventory::lookUpBook()
{
	string term, yesno;
	int choice, searched[sizeI], counter = 0;
	bool exit = false;

	try
	{
		while (!exit)
		{
			system("cls");
			cout << "{ LOOK UP BOOK }" << endl << endl;
			cout << "Search for a book via:" << endl;
			cout << "1. [Title]" << endl;
			cout << "2. [ISBN]" << endl;
			cout << "3. [Author]" << endl;
			cout << "4. [Exit to Inventory Menu]" << endl << endl;
			cout << "Please enter choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore();

			if (choice > 0 && choice < 5)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl;
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 2:
					cout << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl;
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 3:
					cout << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl;
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 4:
					cout << "{ EXITING }" << endl;
					system("pause");
					exit = true;
					break;
				}
			}
			else
			{
				cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
				cin.clear();
				system("pause");
				break;
			}

			if (!exit)
			{
				system("cls");
				cout << "{ SEARCH RESULTS }" << endl;
				if (counter == 0)
					throw "Unable to find books.";
				else
				{
					for (int j = 0; j < counter; j++)
					{
						int t = searched[j];
						cout << store.get(t).toString() << endl << endl;
					}
				}

				cout << "Would you like to continue?: ";
				cin >> yesno;

				if (yesno == "N" || yesno == "n")
				{
					exit = true;
					break;
				}
				else if (yesno == "Y" || yesno == "y")
					continue;
				else
				{
					cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
					system("pause");
					exit = true;
					break;
				}
			}
		}
	}
	catch (char* error)
	{
		cout << error << endl << endl;
		cin.clear();
		system("pause");
		return;
	}
	
}

void Inventory::addBook()
{
	int quant, choice = 0;
	double cost, price;
	string tit, isbn, auth, pub, yesno;
	bool exit = false;

	try
	{
		while (!exit)
		{
			system("cls");
			cout << "{ ADD BOOK }" << endl << endl;
			cout << "1. [Add Book]" << endl;
			cout << "2. [Exit to Inventory Menu]" << endl << endl;
			cout << "Please enter your choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore();

			if (choice > 0 && choice < 3)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "{ NEW BOOK }" << endl;
					cout << "Please enter title: ";
					getline(cin, tit);
					cin.clear();
					cout << "Please enter ISBN: ";
					getline(cin, isbn);
					cin.clear();
					cout << "Please enter author: ";
					getline(cin, auth);
					cin.clear();
					cout << "Please enter publisher: ";
					getline(cin, pub);
					cin.clear();
					cout << "Please enter quantity: ";
					cin >> quant;
					cin.clear();
					cout << "Please enter wholesale cost: ";
					cin >> cost;
					cin.clear();
					cout << "Please enter retail price: ";
					cin >> price;
					cin.clear();
					cin.ignore();
					break;

				case 2:
					exit = true;
					break;
				}
			}
			else
			{
				cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				system("pause");
				addBook();
			}

			if (!exit)
			{
				Book newBook(isbn, tit, auth, pub, 10, 10, 1990, quant, cost, price);
				if (store.add(newBook))
					cout << "{ BOOK SUCCESSFULLY ADDED }" << endl;

				cout << "Would you like to continue? ";
				cin >> yesno;

				if (yesno == "N" || yesno == "n")
				{
					exit = true;
					break;
				}
				else if (yesno == "Y" || yesno == "y")
					continue;
				else
				{
					cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
					exit = true;
					system("pause");
					break;
				}
			}
		}
	}
	catch (char* error)
	{
		cout << error << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		system("pause");
		addBook();
	}
}

void Inventory::editBook()
{
	double price, tempDbl;
	int choice, quant, month, day, year, tempInt, searchResult;
	string term, yesno, tempStr;
	bool exit = false, found = false;

	system("cls");
	cout << "{ EDIT BOOK }" << endl << endl;
	cout << "Search by:" << endl;
	cout << "1. [Title]" << endl;
	cout << "2. [ISBN]" << endl;
	cout << "3. [Author]" << endl;
	cout << "4. [Exit to Inventory Menu]" << endl << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	cin.clear();
	cin.ignore();

	try
	{
		while (!found)
		{
			if (choice > 0 && choice < 5)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 4:
					found = true;
					exit = true;
					break;
				}
			}
			else
			{
				cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
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

	while (!exit && found)
	{
		Book &temp = store.get(searchResult);

		system("cls");
		cout << "\n------------\n" << endl << temp.toString() << endl << "\n------------\n" << endl;
		cout << "Select attribute to edit:" << endl;
		cout << "1. [Title]" << endl;
		cout << "2. [ISBN]" << endl;
		cout << "3. [Author]" << endl;
		cout << "4. [Publisher]" << endl;
		cout << "5. [Date]" << endl;
		cout << "6. [Quantity]" << endl;
		cout << "7. [Wholesale Cost]" << endl;
		cout << "8. [Retail Price]" << endl;
		cout << "9. [Return to Inventory Menu]" << endl << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		cin.clear();

		if (choice > 0 && choice < 10)
		{
			system("cls");
			switch (choice)
			{
			case 1:
				cout << "Please enter new title: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getTitle();
				temp.setTitle(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getTitle() << "] }\n" << endl;
				break;

			case 2:
				cout << "Please enter new ISBN: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getISBN();
				temp.setISBN(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getISBN() << "] }\n" << endl;
				break;

			case 3:
				cout << "Please enter new author: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getAuthor();
				temp.setAuthor(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getAuthor() << "] }\n" << endl;
				break;

			case 4:
				cout << "Please enter new publisher: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getPublisher();
				temp.setPublisher(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getPublisher() << "] }\n" << endl;
				break;

			case 5:
				cout << "Please enter new month (MM): ";
				cin.ignore();
				cin >> month;
				cout << "Please enter new day (DD): ";
				cin.ignore();
				cin >> day;
				cout << "Please enter new year (YYYY): ";
				cin.ignore();
				cin >> year;

				cin.clear();

				tempStr = temp.getDate();
				temp.setDate(month, day, year);
				temp.setMonth(month);
				temp.setDay(day);
				temp.setYear(year);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getDate() << "] }\n" << endl;
				break;
				
			case 6:
				cout << "Please enter new quantity: ";
				cin.ignore();
				cin >> quant;
				cin.clear();

				tempInt = temp.getQuantity();
				temp.setQuantity(quant);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempInt << "] TO: [" << temp.getQuantity() << "] }\n" << endl;
				break;

			case 7:
				cout << "Please enter new wholesale cost: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getWholesaleCost();
				temp.setWholesaleCost(price);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempDbl << "] TO: [" << temp.getWholesaleCost() << "] }\n" << endl;
				break;

			case 8:
				cout << "Please enter new retail price: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getRetailPrice();
				temp.setRetailPrice(price);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempDbl << "] TO: [" << temp.getRetailPrice() << "] }\n" << endl;
				break;

			case 9:
				exit = true;
				break;
			}
		}
		else
		{
			cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
			cin.clear();
			system("pause");
			continue;
		}

		if (!exit)
		{
			cout << "Would you like to continue? ";
			cin >> yesno;

			if (yesno == "N" || yesno == "n")
			{
				exit = true;
				break;
			}
			else if (yesno == "Y" || yesno == "y")
				continue;
			else
			{
				cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
				exit = true;
				system("pause");
			}
		}
	}
}

void Inventory::deleteBook()
{
	int choice, searchResult;
	string term;
	bool exit = false, found = false;

	system("cls");
	cout << "{ REMOVE BOOK }" << endl << endl;
	cout << "Search for a book to remove:" << endl;
	cout << "1. [Title]" << endl;
	cout << "2. [ISBN]" << endl;
	cout << "3. [Author]" << endl;
	cout << "4. [Exit to Inventory Menu]" << endl << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	cin.clear();
	cin.ignore();

	try
	{
		while (!found)
		{
			if (choice > 0 && choice < 5)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 4:
					found = true;
					exit = true;
					break;
				}
			}
			else
			{
				cout << "\n{ INVALID OPTION - PRESS ENTER TO CONTINUE }\n" << endl;
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