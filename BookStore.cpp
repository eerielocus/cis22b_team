#define _CRT_SECURE_NO_WARNINGS

#include "BookStore.h"

using namespace std;

BookStore::BookStore() { count = 0; }

BookStore::BookStore(string input) 
{ 
	count = 0;
	file = input; 
	bookData();
}

void BookStore::menu() 
{ 
	cout << "\n\nThis ran.\n\n";
	return; 
}

void BookStore::add(Book book)
{
	if (count < 25)
	{
		bookList[count] = book;
		count++;
	}
	else
		cout << "Too many books!" << endl;
}

void BookStore::remove(int index)
{
	// In progress.
}

void BookStore::bookData()
{
	ifstream in;
	in.open(file, ios::in);

	while (!in.eof())
	{
		Book temp;
		in >> temp;
		add(temp);
	}
	in.close();
}

Book & BookStore::get(int index) { return bookList[index]; }

int BookStore::getCount() { return count; }

int BookStore::findBook(string type, int choice)
{
	int result;
	while (choice > 0 && choice < 4)
	{
		if (choice == 1)
		{
			cout << endl << "Searching using book title:" << endl;
			for (int i = 0; i < count; i++)
			{
				if (!bookList[i].title.compare(type))
				{
					result = i;
					return result;
				}
			}
		}
			
		if (choice == 2)
		{
			cout << endl << "Searching using book ISBN:" << endl;
			for (int i = 0; i < count; i++)
			{
				if (!bookList[i].ISBN.compare(type))
				{
					result = i;
					return result;
				}
			}
		}
		if (choice == 3)
		{
			cout << endl << "Searching using book author:" << endl;
			for (int i = 0; i < count; i++)
			{
				if (!bookList[i].author.compare(type))
				{
					result = i;
					return result;
				}
			}
		}


	}
}