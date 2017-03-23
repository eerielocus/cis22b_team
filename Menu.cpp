#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"

using namespace std;

/*
Menu Module: Stores the referenced Bookstore class to be accessed by the other modules that
inherit off of it. Provides virtual menu function for child classes to redefine.
*/

Menu::Menu(BookStore *store) : store(*store) { }

void Menu::menu() { return; }