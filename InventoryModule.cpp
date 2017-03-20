#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"

using namespace std;

/*
Inventory Module: Allow searching, adding, removing and editing of inventory of books.

Pseudocode:
Main menu
	Ask user for choice
		1. Search
		2. Add
		3. Remove
		4. Edit
		5. Exit
*/

Inventory::Inventory(BookStore *store) : Menu(store) { }		// Constructor utilize referenced BookStore class and pass to Menu.

void Inventory::menu()
{
	int choice;
	bool exit = false;

	while (!exit)
	{
	system("cls");

	cout << endl;
	cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
	cout << setw(35) << "{ INVENTORY MENU }         " << endl << endl;
	cout << setw(35) << "1. [ Search for Book ]     " << endl;
	cout << setw(35) << "2. [ Add Book ]            " << endl;
	cout << setw(35) << "3. [ Remove Book ]         " << endl;
	cout << setw(35) << "4. [ Edit Book ]           " << endl;
	cout << setw(35) << "5. [ Return to Main Menu ] " << endl << endl;
	cout << setw(25) << "Enter choice: ";
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
			cout << endl;
			cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
			cout << setw(35) << "{ LOOK UP BOOK }           " << endl << endl;
			cout << setw(25) << "Search via:   " << endl;
			cout << setw(35) << "1. [ Title ]               " << endl;
			cout << setw(35) << "2. [ ISBN ]                " << endl;
			cout << setw(35) << "3. [ Author ]              " << endl;
			cout << setw(35) << "4. [ Exit ]                " << endl << endl;
			cout << setw(25) << "Enter choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore();

			if (choice > 0 && choice < 5)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << endl << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl << endl;
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 2:
					cout << endl << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl << endl;
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 3:
					cout << endl << "{ MAY ENTER PARTIAL SEARCH TERMS }" << endl << endl;
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					counter = store.lookUp(term, choice, searched);
					break;

				case 4:
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
				cout << endl << "{ SEARCH RESULTS }" << endl;
				if (counter == 0)
					throw "Unable to find books.";
				else
				{
					for (int j = 0; j < counter; j++)
					{
						int t = searched[j];
						cout << "------------" << endl << endl;
						cout << store.get(t).toString() << endl << endl;
					}
				}

				cout << "Would you like to continue?: (Y/N) ";
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
			cout << endl;
			cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
			cout << setw(35) << "{ ADD BOOK }               " << endl << endl;
			cout << setw(35) << "1. [ Add Book ]            " << endl;
			cout << setw(35) << "2. [ Exit ]                " << endl << endl;
			cout << setw(25) << "Enter choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore();

			if (choice > 0 && choice < 3)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << endl;
					cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
					cout << setw(35) << "{ NEW BOOK }               " << endl << endl;
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
				// Current time input using <ctime>.
				int month, day, year;
				time_t rawtime;
				struct tm* timeinfo;

				// Pass rawtime into appropriate function for localtime.
				time(&rawtime);
				timeinfo = localtime(&rawtime);

				// Store current date to insert into new Book constructor.
				month = timeinfo->tm_mon + 1;
				day = timeinfo->tm_mday;
				year = timeinfo->tm_year + 1900;

				// Create new book to add to list.
				Book newBook(isbn, tit, auth, pub, month, day, year, quant, cost, price);

				// Check if add is successful.
				if (store.add(newBook))
					cout << "\n------------\n" << "{ BOOK SUCCESSFULLY ADDED }" << endl << endl;

				cout << "Would you like to continue?: (Y/N) ";
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
	cout << endl;
	cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
	cout << setw(35) << "{ EDIT BOOK }              " << endl << endl;
	cout << setw(25) << "Search by:    " << endl;
	cout << setw(35) << "1. [ Title ]               " << endl;
	cout << setw(35) << "2. [ ISBN ]                " << endl;
	cout << setw(35) << "3. [ Author ]              " << endl;
	cout << setw(35) << "4. [ Exit ]                " << endl << endl;
	cout << setw(25) << "Enter choice: ";
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
				case 1: // Search by title.
					cout << endl;
					cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
					cout << setw(35) << "{ EDIT BOOK }              " << endl << endl;
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 2: // ISBN.
					cout << endl;
					cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
					cout << setw(35) << "{ EDIT BOOK }              " << endl << endl;
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 3: // Author.
					cout << endl;
					cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
					cout << setw(35) << "{ EDIT BOOK }              " << endl << endl;
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store.findBook(term, choice);
					found = true;
					break;

				case 4: // Exit.
					found = true;
					exit = true;
					break;
				}
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

	while (!exit && found)
	{
		Book &temp = store.get(searchResult);

		system("cls");
		cout << "------------" << endl << temp.toString() << endl << "------------" << endl << endl;
		cout << setw(25) << "Select:       " << endl;
		cout << setw(35) << "1. [ Title ]               " << endl;
		cout << setw(35) << "2. [ ISBN ]                " << endl;
		cout << setw(35) << "3. [ Author ]              " << endl;
		cout << setw(35) << "4. [ Publisher ]           " << endl;
		cout << setw(35) << "5. [ Date ]                " << endl;
		cout << setw(35) << "6. [ Quantity ]            " << endl;
		cout << setw(35) << "7. [ Wholesale Cost ]      " << endl;
		cout << setw(35) << "8. [ Retail Price ]        " << endl;
		cout << setw(35) << "9. [ Exit ]                " << endl << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> choice;
		cin.clear();

		if (choice > 0 && choice < 10)
		{
			switch (choice)
			{
			case 1: // Title.
				cout << endl;
				cout << setw(28) << "Enter new title: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getTitle();
				temp.setTitle(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getTitle() << "] }\n" << endl;
				break;

			case 2: // ISBN.
				cout << endl;
				cout << setw(27) << "Enter new ISBN: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getISBN();
				temp.setISBN(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getISBN() << "] }\n" << endl;
				break;

			case 3: // Author.
				cout << endl;
				cout << setw(29) << "Enter new author: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getAuthor();
				temp.setAuthor(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getAuthor() << "] }\n" << endl;
				break;

			case 4: // Publisher.
				cout << endl;
				cout << setw(32) << "Enter new publisher: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getPublisher();
				temp.setPublisher(term);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempStr << "] TO: [" << temp.getPublisher() << "] }\n" << endl;
				break;

			case 5: // Date.
				cout << endl;
				cout << setw(33) << "Enter new month (MM): ";
				cin.ignore();
				cin >> month;
				cout << setw(31) << "Enter new day (DD): ";
				cin.ignore();
				cin >> day;
				cout << setw(34) << "Enter new year (YYYY): ";
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
				
			case 6: // Quantity.
				cout << endl;
				cout << setw(31) << "Enter new quantity: ";
				cin.ignore();
				cin >> quant;
				cin.clear();

				tempInt = temp.getQuantity();
				temp.setQuantity(quant);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempInt << "] TO: [" << temp.getQuantity() << "] }\n" << endl;
				break;

			case 7: // Wholesale.
				cout << endl;
				cout << setw(37) << "Enter new wholesale cost: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getWholesaleCost();
				temp.setWholesaleCost(price);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempDbl << "] TO: [" << temp.getWholesaleCost() << "] }\n" << endl;
				break;

			case 8: // Retail.
				cout << endl;
				cout << setw(35) << "Enter new retail price: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getRetailPrice();
				temp.setRetailPrice(price);

				cout << "\n{ SUCCESSFULLY CHANGED: [" << tempDbl << "] TO: [" << temp.getRetailPrice() << "] }\n" << endl;
				break;

			case 9: // Exit.
				exit = true;
				break;
			}
		}
		else
		{
			cout << "\n{ INVALID OPTION }\n" << endl;
			cin.clear();
			system("pause");
			continue;
		}

		if (!exit)
		{
			cout << "Would you like to continue?: (Y/N) ";
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
				cout << "\n{ INVALID OPTION }\n" << endl;
				exit = true;
				system("pause");
			}
		}
	}
}

void Inventory::deleteBook()
{
	int choice, searchResult;
	string term, yesno;
	bool exit = false;

	while (!exit)
	{
		bool found = false;

		system("cls");
		cout << endl;
		cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
		cout << setw(35) << "{ REMOVE BOOK }            " << endl << endl;
		cout << setw(25) << "Search via:   " << endl;
		cout << setw(35) << "1. [Title]                 " << endl;
		cout << setw(35) << "2. [ISBN]                  " << endl;
		cout << setw(35) << "3. [Author]                " << endl;
		cout << setw(35) << "4. [Exit]                  " << endl << endl;
		cout << setw(25) << "Enter choice: ";
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
					case 1: // Title.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ REMOVE BOOK }            " << endl << endl;
						cout << setw(31) << "Enter title to search: ";
						getline(cin, term);
						cin.clear();
						searchResult = store.findBook(term, choice);
						found = true;
						break;

					case 2: // ISBN.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ REMOVE BOOK }            " << endl << endl;
						cout << setw(30) << "Enter ISBN to search: ";
						getline(cin, term);
						cin.clear();
						searchResult = store.findBook(term, choice);
						found = true;
						break;

					case 3: // Author.
						cout << endl;
						cout << setw(35) << "{ SERENDIPITY BOOKSELLERS }" << endl << endl;
						cout << setw(35) << "{ REMOVE BOOK }            " << endl << endl;
						cout << setw(32) << "Enter author to search: ";
						getline(cin, term);
						cin.clear();
						searchResult = store.findBook(term, choice);
						found = true;
						break;

					case 4: // Exit.
						found = true;
						exit = true;
						break;
					}
				}

				else
				{
					cout << "\n{ INVALID OPTION }\n" << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					system("pause");
					break;
				}

				if (found)
				{
					if (store.remove(searchResult))
						cout << "Remove successful." << endl << endl;
				}

				if (!exit)
				{
					cout << "Would you like to continue?: (Y/N) ";
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
						cout << "\n{ INVALID OPTION }\n" << endl;
						exit = true;
						system("pause");
					}
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
}