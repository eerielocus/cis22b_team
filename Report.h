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
	Book books[25];

public:
	Report(BookStore*);

	void menu();
	void inventory();
	void wholesaleValue();
	void retailValue();
	void quantity();
	void cost();
	void age();
};
#endif