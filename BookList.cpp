#define _CRT_SECURE_NO_WARNINGS
#include "BookList.h"
#include <fstream>
#include <string>

using namespace std;


BookList::BookList(string s) { fileName = s; }

void BookList::add(Book &b)
{
	bookList.push_back(b);
}

void BookList::remove(int index)
{
	bookList.erase(bookList.begin() + index);
}

Book& BookList::get(int index)
{
	return bookList.at(index);
}

int BookList::getSize() const
{
	return bookList.size();
}

