#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BookStore.h"
#include "InventoryModule.h"
using namespace std;

void reportsModule();
int main()
{
	int moduleChoice;
	bool flag1 = true;
	while (flag1 == true)
	{
		system("cls");
		cout << endl;
		cout << setw(35) << "Serendipty Booksellers   " << endl;
		cout << setw(35) << endl;
		cout << setw(35) << "1. to use the cash register" << endl;
		cout << setw(35) << "2. to use inventory        " << endl;
		cout << setw(35) << "3. to use reports          " << endl;
		cout << setw(35) << "4. to quit                 " << endl;
		cout << setw(35) << endl;
		cout << setw(25) << "Enter choice: ";
		cin >> moduleChoice;
		if (moduleChoice < 5 && moduleChoice > 0)
		{
			switch (moduleChoice)
			{
			case 1:
				//CashRegister();
				break;
			case 2:
				//inventory();
				break;
			case 3:
				reportsModule();
				break;
			case 4:
				flag1 = false;
				break;
			}
		}
		else
		{
			cout << "Incorrect output, try again..";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	system("pause");
	return 0;
}

void  reportsModule()
{
	cout << "Reports Module" << endl;
}