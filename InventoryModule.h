#ifndef INVENTORY
#define INVENTORY

#include "Book.h"
#include "BookStore.h"
#include <string>
#include <iostream>

using namespace std;

class Inventory : public BookStore
{
public:
	Inventory();

	void addBook();
	void deleteBook();
};

#endif