#ifndef INVENTORY
#define INVENTORY

#include "Book.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Inventory : public Menu
{
protected:
	int bookCount;
	const static int sizeI = 30;

public:
	Inventory(BookStore*);

	void menu();
	void lookUpBook();
	void addBook();
	void editBook();
	void deleteBook();
};

#endif