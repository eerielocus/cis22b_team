#define _CRT_SECURE_NO_WARNINGS

#include "BookStore.h"
#include <string>

using namespace std;

BookStore::BookStore() { count = 0; }

BookStore::BookStore(string input) 
{ 
	file = input; 
	count = 0;
}

void BookStore::add(Book &book)
{
	bookList[count] = book;
	count++;
}

void BookStore::remove(int index)
{
	// In progress.
}

Book BookStore::get(int index)
{
	return bookList[index];
}