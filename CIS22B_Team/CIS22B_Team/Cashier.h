#ifndef CASHIER_H
#define CASHIER_H

#include "Book.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Cashier : public Menu
{
public:
	Cashier(BookStore*);

	void menu();
	string truncate(string);
};

#endif