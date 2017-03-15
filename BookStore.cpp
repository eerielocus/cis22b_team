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

void toLower(basic_string<char>& s)
{
	for (basic_string<char>::iterator p = s.begin(); p != s.end(); ++p) 
		*p = tolower(*p);
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
	if (index == (size - 1))
		bookList[index] = Book();

	for (int i = index; i < (size - 1); i++)
		bookList[i] = bookList[i + 1];

	count--;

	for (int k = count; k < size; k++)
		bookList[k] = Book();
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
	if (choice == 1)
	{
		cout << endl << "Searching using book title:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (!bookList[i].title.compare(type))
			{
				cout << "Found!" << endl << endl;
				result = i;
				return result;
			}
		}

		throw "No matching item found.";
		system("pause");
		return NULL;
	}

	if (choice == 2)
	{
		cout << endl << "Searching using book ISBN:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (!bookList[i].ISBN.compare(type))
			{
				cout << "Found!" << endl << endl;
				result = i;
				return result;
			}
		}

		throw "No matching item found.";
		system("pause");
		return NULL;
	}

	if (choice == 3)
	{
		cout << endl << "Searching using book author:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (!bookList[i].author.compare(type))
			{
				cout << "Found!" << endl << endl;
				result = i;
				return result;
			}
		}

		throw "No matching item found.";
		system("pause");
		return NULL;
	}
	return NULL;
}

void BookStore::lookUp(string type, int choice)
{
	int storage[size], counter = 0;

	if (choice == 1)
	{
		cout << endl << "Searching using book title:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].title;
			toLower(temp);
			toLower(type);
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				storage[counter] = i;
				counter++;
			}
		}
	}

	if (choice == 2)
	{
		cout << endl << "Searching using book ISBN:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].ISBN;
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				storage[counter] = i;
				counter++;
			}
		}
	}

	if (choice == 3)
	{
		cout << endl << "Searching using book author:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].author;
			toLower(temp);
			toLower(type);
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				storage[counter] = i;
				counter++;
			}
		}
	}

	if (counter == 0)
		throw "Unable to find books.";
	else
	{
		for (int j = 0; j < counter; j++)
		{
			int t = storage[j];
			cout << bookList[t].toString() << endl << endl;
		}
	}
	system("pause");
}
