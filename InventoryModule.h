#ifndef INVENTORY
#define INVENTORY

#include "Book.h"
#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

class Inventory : public Menu
{
protected:
	const static int sizeI = 25;

public:
	Inventory(BookStore*);

	void menu();
	void lookUpBook();
	void addBook();
	void editBook();
	void deleteBook();
};

#endif