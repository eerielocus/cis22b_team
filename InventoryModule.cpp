#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"

using namespace std;

Inventory::Inventory(BookStore *store) : Menu(store) {}		// Constructor utilize referenced BookStore class and pass to Menu.

void Inventory::menu()
{
	int choice;
	bool exit = false;

	cout << "Inventory Menu" << endl << endl;
	cout << "Select option below:" << endl;
	cout << "1. Look up book" << endl;
	cout << "2. Add book" << endl;
	cout << "3. Remove book" << endl;
	cout << "4. Edit book" << endl;
	cout << "5. Return to main menu" << endl;
	cout << "Please enter in choice: ";
	cin >> choice;
	
	while (exit == false)
	{
		if (choice > 0 && choice < 5)
		{
			system("cls");
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
				break;
			}
		}
	}
}

void Inventory::lookUpBook()
{
	string term, yesno;
	int choice;
	bool exit = false;

	system("cls");
	cout << "Search for a book via:" << endl;
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cout << "Please enter choice: ";
	cin >> choice;
	cin.clear();
	cin.ignore();

	try
	{
		while (exit == false)
		{
			if (choice > 0 && choice < 4)
			{
				system("cls");
				cout << "[You may type in partial search terms.]" << endl;
				switch (choice)
				{
				case 1:
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					store->lookUp(term, choice);
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					store->lookUp(term, choice);
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					store->lookUp(term, choice);
					break;
				}
			}
			else
			{
				cout << "Invalid option selected. Please try again." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				system("pause");
				lookUpBook();
			}
		}
	}
	catch (char* error)
	{
		cout << error << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		system("pause");
		lookUpBook();
	}

	cout << "Would you like to continue? ";
	cin >> yesno;

	if (yesno == "N" || yesno == "n")
	{
		exit = true;
		editBook();
	}
}

void Inventory::addBook()
{
	
	int search = store->findBook("Lord of the Flies", 1);
	if (search == NULL)
		cout << "Please search again." << endl;
	else
	{
		Book &searchResult = store->get(search);
		cout << "Changing." << endl << endl;
		searchResult.setDay(12);
		cout << searchResult.getYear() << endl << endl;
		cout << searchResult.toString() << endl << endl;
	}
}

void Inventory::editBook()
{
	int choice, attr, searchResult = NULL;
	string term, yesno, tempStr;
	bool exit = false;

	system("cls");
	cout << "Search for a book to edit:" << endl;
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cin >> choice;
	cin.clear();
	cin.ignore();

	try
	{
		while (searchResult == NULL)
		{
			if (choice > 0 && choice < 4)
			{
				system("cls");
				switch (choice)
				{
				case 1:
					cout << "Please enter title to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
					break;

				case 2:
					cout << "Please enter ISBN to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
					break;

				case 3:
					cout << "Please enter author to search: ";
					getline(cin, term);
					cin.clear();
					searchResult = store->findBook(term, choice);
					break;
				}
			}
			else
			{
				cout << "Invalid option selected. Please try again." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				system("pause");
				editBook();
			}
		}
	}
	catch (char* error)
	{
		cout << error << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		system("pause");
		editBook();
	}

	while (exit == false)
	{
		system("cls");
		cout << "Select attribute to edit:" << endl;
		cout << "1. Title" << endl;
		cout << "2. ISBN" << endl;
		cout << "3. Author" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Date" << endl;
		cout << "6. Wholesale Cost" << endl;
		cout << "7. Retail Price" << endl;
		cout << "8. Return to Inventory Menu" << endl;
		cin >> choice;
		cin.clear();

		Book &temp = store->get(searchResult);
		if (choice > 0 && choice < 8)
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
				int input[3];
				cout << "Please enter new date as follows (MM/DD/YYYY) seperated with '/': ";
				cin.ignore();
				getline(cin, term);
				


				cin.clear();

				tempStr = temp.getDate();
				temp.setDate(input[0], input[1], input[2]);

				cout << "Successfully changed: " << tempStr << " to: " << temp.getDate() << endl << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid option selected. Please try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Would you like to continue? ";
		cin >> yesno;

		if (yesno == "N" || yesno == "n")
		{
			exit = true;
			editBook();
		}
	}
}

void Inventory::deleteBook()
{
	store->remove(1);
	store->remove(24);
	cout << store->getCount() << endl << endl;
	for (int i = 0; i < 25; i++)	//Temporary print test.
	{
		Book result = store->get(i);	// Use similar pointer to get functions.
		cout << result.toString() << endl << endl;
	}
}