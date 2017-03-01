#ifndef BOOKSTORE
#define BOOKSTORE

#include "Book.h"
#include <string>

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

	void add(Book &);		// Add book to list.
	void remove(int);		// Remove book from list. (unfinished)
	Book& get(int);			// Get book from list via index.

};

#endif