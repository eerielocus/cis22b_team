#define _CRT_SECURE_NO_WARNINGS

#include "InventoryModule.h"
#include "BookStore.h"
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	BookStore bookMod("BookList.txt");		// Create list and read file and input into array.
	Inventory invMod(&bookMod);				// Pass created object array reference through the Menu constructor for Inventory.

	invMod.menu();	// Testing add function.




	system("Pause");
	return 0;
}