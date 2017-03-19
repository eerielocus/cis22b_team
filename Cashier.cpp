#define _CRT_SECURE_NO_WARNINGS

#include "Cashier.h"

using namespace std;

cashier::cashier(BookStore* store) : Menu(store) {}

void cashier::menu()
{
	int index[25];
	int i = 0;
	int choice = 0;
	string term = " ";
	do
	{
		system("cls");
		std::cout << std::setw(20) << "Would you like to search for a book by" << std::endl;
		std::cout << std::setw(20) << "1: Title" << std::endl;
		std::cout << std::setw(20) << "2: ISBN" << std::endl;
		std::cout << std::setw(20) << "3: Author" << std::endl;
		std::cout << std::setw(20) << "4: Exit search" << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(20) << "Enter Choice: ";
		cin >> choice;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(20) << "Please enter your search term: ";
		getline(cin, term);
		std::cout << std::endl;
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
		case 2:
		case 3:
			if ((store.findBook(term, choice)) != NULL)
			{
				index[i] = store.findBook(term, choice);
				i++;
			}
			else
				break;
		case 4:
			std::cout << std::setw(20) << "Proceeding to checkout" << std::endl << std::endl;
			break;
		default:
			break;
		}

	} while (choice != 4);

	double subtotal = 0,
		subtax = 0,
		total = 0;

	system("cls");
	std::cout << std::endl;
	std::cout << std::setw(20) << "Serendipity booksellers   " << std::endl;
	std::cout << std::setw(40) << std::endl;
	std::cout << std::setw(40) << std::endl;
	std::cout << std::setw(40) << "Qty   ISBN           Title                         Price   " << std::endl;
	std::cout << std::setw(40) << "___________________________________________________________" << std::endl;// put for loop here to print out all of the book information using the index array and counter
	std::cout << std::setw(40) << std::endl;

	for (int j = 0; j < i; j++)
	{
		std::cout << std::setw(40) << store.get(index[j]).getQuantity() << "   " << store.get(index[j]).getISBN() << "     " << store.get(index[j]).getTitle() << std::right << store.get(index[j]).getRetailPrice() << std::endl;
		subtotal += store.get(index[j]).getRetailPrice();
	}

	subtax = (subtotal * .0725);
	total = (subtotal + subtax);

	std::cout << std::setw(20) << "Subtotal: " << subtotal << std::endl;
	std::cout << std::setw(20) << "Subtax: " << subtax << std::endl;
	std::cout << std::setw(20) << "Total: " << total << std::endl;
	std::cout << std::setw(20) << std::endl;
	std::cout << std::setw(20) << std::endl;
	system("pause");
}