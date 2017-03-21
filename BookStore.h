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
	const static int size = 30;

protected:
	Book bookList[size];			// Book shelf.

public:
	BookStore();
	BookStore(string);

	void menu();

	bool add(Book);					// Add book to list.
	bool remove(int);				// Remove book from list. (unfinished)
	void bookData();				// Input data from file.
	void bookWrite();				// Output data to file.

	void toLower(basic_string<char> &);

	Book & get(int);				// Get book from list via index.
	int getCount();					// Get # of books in list.
	int getOldCount();				// Get # of books initially in list.
	int getSize() const;			// Get size of book shelf.
	int findBook(string, int);		// Find book with exact name.
	int lookUp(string, int, int[]);	// Find book with partial name.
};

#endif