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

// Simple void function to make strings lowercase.
void toLower(basic_string<char>& s)
{
	for (basic_string<char>::iterator p = s.begin(); p != s.end(); ++p) 
		*p = tolower(*p);
}

// Adds passed Book object if there is room. If count is greater than allowed size,
// display error message too many books.
bool BookStore::add(Book book)
{
	if (count < size)
	{
		bookList[count] = book;
		count++;
		return true;
	}
	else
		cout << "Too many books!" << endl;
	return false;
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

// Takes input file data and inserts into appropriate attributes of Book.
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

int BookStore::getSize() const { return size; }

// Full search term book finder. Pass search term string and choice of book attribute.
// Returns an int that is the index of the book found.
// Throws a no match found exception.
int BookStore::findBook(string type, int choice)
{
	int result;
	if (choice == 1)		// Search by title.
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

	if (choice == 2)		// Search by ISBN.
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

	if (choice == 3)		// Search by author.
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

// Partial search term book finder. Pass search term string, choice of book attribute,
// and an array to store indexes that match the search term. 
// Returns an int that is the counter to use for the array holding the stored indexes.
int BookStore::lookUp(string type, int choice, int searched[])
{
	int counter = 0;		// Counter to keep track of how many 'hits' were found to allow for proper display.

	if (choice == 1)		// Search by title.
	{
		cout << endl << "Searching using book title:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].title;
			toLower(temp);
			toLower(type);
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				searched[counter] = i;
				counter++;
			}
		}
		return counter;
	}

	if (choice == 2)		// Search by ISBN.
	{
		cout << endl << "Searching using book ISBN:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].ISBN;
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				searched[counter] = i;
				counter++;
			}
		}
		return counter;
	}

	if (choice == 3)		// Search by author.
	{
		cout << endl << "Searching using book author:" << endl;
		for (int i = 0; i < count; i++)
		{
			string temp = bookList[i].author;
			toLower(temp);
			toLower(type);
			if (type.find(temp.c_str(), 0, type.size()) == 0)
			{
				searched[counter] = i;
				counter++;
			}
		}
		return counter;
	}
	return counter;
}
