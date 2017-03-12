#ifndef MENU_H
#define MENU_H

#include "BookStore.h"

using namespace std;

class Menu
{
protected:
	BookStore *store;

public:
	Menu(BookStore *store);

	virtual void menu();

};

#endif