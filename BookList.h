#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <vector>
#include "Book.h"



using namespace std;

class BookList
{
private:
	vector<Book> bookList;
	string fileName;

public:
	BookList(string);
	void add(Book&);
	void remove(int);
	Book& get(int);
	int getSize() const;
};
#endif