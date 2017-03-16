#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"

using namespace std;

Inventory::Inventory(BookStore *store) : Menu(store) { }		// Constructor utilize referenced BookStore class and pass to Menu.

void Inventory::menu()
{
	int choice;
	bool exit = false;

	while (exit == false)
	{
	system("cls");
	cout << "{ INVENTORY MENU }" << endl << endl;
	cout << "Select option below:" << endl;
	cout << "1. Look up book" << endl;
	cout << "2. Add book" << endl;
	cout << "3. Remove book" << endl;
	cout << "4. Edit book" << endl;
	cout << "5. Return to main menu" << endl << endl;
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
				break;
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
		while (exit == false)
		{
			system("cls");
			cout << "{ LOOK UP BOOK }" << endl << endl;
			cout << "Search for a book via:" << endl;
			cout << "1. Title" << endl;
			cout << "2. ISBN" << endl;
			cout << "3. Author" << endl;
			cout << "4. Exit to Inventory menu" << endl << endl;
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
					cout << "{ May enter partial search terms. }" << endl;
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					counter = store->lookUp(term, choice, searched);
					break;

				case 2:
					cout << "{ May enter partial search terms. }" << endl;
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					counter = store->lookUp(term, choice, searched);
					break;

				case 3:
					cout << "{ May enter partial search terms. }" << endl;
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					counter = store->lookUp(term, choice, searched);
					break;

				case 4:
					cout << "Exiting." << endl;
					system("pause");
					exit = true;
					break;
				}
			}
			else
			{
				cout << "Invalid option selected. Please try again." << endl;
				cin.clear();
				system("pause");
				break;
			}

			if (choice != 4)
			{
				system("cls");
				cout << "Search results: " << endl;
				if (counter == 0)
					throw "Unable to find books.";
				else
				{
					for (int j = 0; j < counter; j++)
					{
						int t = searched[j];
						cout << store->get(t).toString() << endl << endl;
					}
				}

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
					cout << "Invalid response. Returning to menu." << endl;
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
		while (exit == false)
		{
			system("cls");
			cout << "{ ADD BOOK }" << endl << endl;
			cout << "1. Add book" << endl;
			cout << "2. Exit to Inventory menu" << endl << endl;
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
					cout << "For the new book:" << endl;
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
				cout << "Invalid option selected. Please try again." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				system("pause");
				addBook();
			}

			if (choice != 2)
			{
				Book newBook(isbn, tit, auth, pub, 10, 10, 1990, quant, cost, price);
				if (store->add(newBook))
					cout << "Book successfully added!" << endl;

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
					cout << "Invalid response. Returning to menu." << endl;
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
	cout << "Search for a book to edit:" << endl;
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cout << "4. Exit to Inventory menu" << endl << endl;
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
					searchResult = store->findBook(term, choice);
					found = true;
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
					found = true;
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
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
				cout << "Invalid option selected. Please try again." << endl;
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
		Book &temp = store->get(searchResult);

		system("cls");
		cout << "-----" << endl << temp.toString() << endl << "-----" << endl;
		cout << "Select attribute to edit:" << endl;
		cout << "1. Title" << endl;
		cout << "2. ISBN" << endl;
		cout << "3. Author" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Date" << endl;
		cout << "6. Quantity" << endl;
		cout << "7. Wholesale Cost" << endl;
		cout << "8. Retail Price" << endl;
		cout << "9. Return to previous menu" << endl << endl;
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

				cout << "Successfully changed: " << tempStr << " to: " << temp.getTitle() << endl << endl;
				break;

			case 2:
				cout << "Please enter new ISBN: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getISBN();
				temp.setISBN(term);

				cout << "Successfully changed: " << tempStr << " to: " << temp.getISBN() << endl << endl;
				break;

			case 3:
				cout << "Please enter new author: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getAuthor();
				temp.setAuthor(term);

				cout << "Successfully changed: " << tempStr << " to: " << temp.getAuthor() << endl << endl;
				break;

			case 4:
				cout << "Please enter new publisher: ";
				cin.ignore();
				getline(cin, term);
				cin.clear();

				tempStr = temp.getPublisher();
				temp.setPublisher(term);

				cout << "Successfully changed: " << tempStr << " to: " << temp.getPublisher() << endl << endl;
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

				cout << "Successfully changed: " << tempStr << " to: " << temp.getDate() << endl << endl;
				break;
				
			case 6:
				cout << "Please enter new quantity: ";
				cin.ignore();
				cin >> quant;
				cin.clear();

				tempInt = temp.getQuantity();
				temp.setQuantity(quant);

				cout << "Successfully changed: " << tempInt << " to: " << temp.getQuantity() << endl << endl;
				break;

			case 7:
				cout << "Please enter new wholesale cost: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getWholesaleCost();
				temp.setWholesaleCost(price);

				cout << "Successfully changed: " << tempDbl << " to: " << temp.getWholesaleCost() << endl << endl;
				break;

			case 8:
				cout << "Please enter new retail price: ";
				cin.ignore();
				cin >> price;
				cin.clear();

				tempDbl = temp.getRetailPrice();
				temp.setRetailPrice(price);

				cout << "Successfully changed: " << tempDbl << " to: " << temp.getRetailPrice() << endl << endl;
				break;

			case 9:
				exit = true;
				break;
			}
		}
		else
		{
			cout << "Invalid option selected. Please try again." << endl;
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
				cout << "Invalid response. Returning to menu." << endl;
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
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cout << "4. Exit to Inventory menu" << endl << endl;
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
					searchResult = store->findBook(term, choice);
					found = true;
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
					found = true;
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
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
				cout << "Invalid option selected. Please try again." << endl;
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