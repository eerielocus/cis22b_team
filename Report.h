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
	void display();
	void wholesaleValue();
	void retailValue();
	void quantity();
	void cost();
	void age();
	void load();
};
#endif