#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;

Book::Book()
{
	ISBN = "";
	bookTitle = "";
	authorName = "";
	publisher = "";
	date;
	quantity = 0;
	wholesaleCost = 0;
	retailCost = 0;
}

Book::Book(string i, string b, string a, string p, int day, int month, int year, int q, double c, double r) : date(day, month, year)
{
	ISBN = i;
	bookTitle = b;
	authorName = a;
	publisher = p;
	quantity = q;
	wholesaleCost = c;
	retailCost = r;
}


string Book::toString(int info)
{
	string temp; //Unfinished.
	return temp;
}

void Book::setISBN(string number)
{
	ISBN = number;
}

void Book::setBookTitle(string title)
{
	bookTitle = title;
}

void Book::setAuthorName(string Aname)
{
	authorName = Aname;
}

void Book::setPublisher(string pub)
{
	publisher = pub;
}
void Book::setQuantity(int number)
{
	quantity = number;
}

void Book::setWholesaleCost(double price)
{
	wholesaleCost = price;
}

void Book::setRetailCost(double sellBack)
{
	retailCost = sellBack;
}

void Book::setDay(int d)
{
	date.setDay(d);
}

void Book::setMonth(int m)
{
	date.setMonth(m);
}

void Book::setYear(int y)
{
	date.setYear(y);
}

string Book::getISBN() const
{
	return ISBN;
}

string Book::getBookTitle() const
{
	return bookTitle;
}

string Book::getAuthorName() const
{
	return authorName;
}

string Book::getPublisher() const
{
	return publisher;
}

int Book::getMonth() const
{
	return date.getMonth();
}

int Book::getDay() const
{
	return date.getDay();
}

int Book::getYear() const
{
	return date.getYear();
}

Date Book::getDate() const
{
	return date;
}

int Book::getQuantity() const
{
	return quantity;
}

double Book::getWholesaleCost() const
{
	return wholesaleCost;
}

double Book::getRetailCost() const
{
	return retailCost;
}