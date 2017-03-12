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

Book & BookStore::get(int index)
{
	return bookList[index];
}

int BookStore::getCount()
{
	return count;
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