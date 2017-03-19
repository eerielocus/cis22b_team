#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "book.h"
#include "bookstore.h"
#include "Menu.h"

using namespace std;

class cashier : public Menu
{
public:
	cashier(BookStore*);
	void menu();
};

#endif