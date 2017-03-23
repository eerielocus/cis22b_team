#ifndef REPORT_H
#define REPORT_H

#include "Book.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Report : public Menu
{
private:
	int size = store.getCount();
	Book books[30];

public:
	Report(BookStore*);

	void menu();
	void display();			// Show all inventory.
	void wholesaleValue();	// List all wholesale value.
	void retailValue();		// List all retail value.
	void quantity();		// Sort by quantity.
	void cost();			// Sort by wholesale cost.
	void age();				// Sort by date added.
	void load();			// Load bookList into temporary list.
};
#endif