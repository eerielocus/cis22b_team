#ifndef BOOKSTORE
#define BOOKSTORE

#include "Book.h"
#include <string>
#include <cctype>
#include <cwctype>
#include <stdexcept>

using namespace std;

class BookStore
{
private:
	string file;
	int count;
	const static int size = 25;

protected:
	Book bookList[size];

public:
	BookStore();
	BookStore(string);

	virtual void menu();

	void add(Book);			// Add book to list.
	void remove(int);		// Remove book from list. (unfinished)
	void bookData();		// Input data from file.

	template <class T>
	void setData(T);

	Book & get(int);		// Get book from list via index.
	int getCount();
	int getSize() const;
	int findBook(string, int);
	int lookUp(string, int, int[]);
};

#endif