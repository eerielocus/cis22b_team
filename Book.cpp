#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;

Book::Book()
{
	ISBN = "";
	title = "";
	author = "";
	publisher = "";
	month = 0;
	day = 0;
	year = 0;
	quantity = 0;
	wholesaleCost = 0;
	retailPrice = 0;
}

Book::Book(string i, string b, string a, string p, int m, int d, int y, int q, double c, double r)
{
	ISBN = i;
	title = b;
	author = a;
	publisher = p;
	month = m;
	day = d;
	year = y;
	date = to_string(month) + "-" + to_string(day) + "-" + to_string(year);
	quantity = q;
	wholesaleCost = c;
	retailPrice = r;
}

void Book::setISBN(string num)
{
	ISBN = num;
}

void Book::setTitle(string tit)
{
	title = tit;
}

void Book::setAuthor(string name)
{
	author = name;
}

void Book::setPublisher(string pub)
{
	publisher = pub;
}
void Book::setQuantity(int num)
{
	quantity = num;
}

void Book::setWholesaleCost(double cost)
{
	wholesaleCost = cost;
}

void Book::setRetailPrice(double price)
{
	retailPrice = price;
}

void Book::setDay(int d)
{
	day = d;
}

void Book::setMonth(int m)
{
	month = m;
}

void Book::setYear(int y)
{
	year = y;
}

string Book::getISBN() const
{
	return ISBN;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getPublisher() const
{
	return publisher;
}

string Book::getDate() const
{
	return date;
}

int Book::getMonth() const
{
	return month;
}

int Book::getDay() const
{
	return day;
}

int Book::getYear() const
{
	return year;
}

int Book::getQuantity() const
{
	return quantity;
}

double Book::getWholesaleCost() const
{
	return wholesaleCost;
}

double Book::getRetailPrice() const
{
	return retailPrice;
}

string Book::toString()
{
	string temp;
	temp += "ISBN: " + ISBN + '\n';
	temp += "Title: " + title + '\n';
	temp += "Author: " + author + '\n';
	temp += "Publisher: " + publisher + '\n';
	temp += "Date Added: " + date + '\n';
	temp += "Quantity: " + to_string(quantity) + '\n';
	temp += "Wholesale Cost: " + to_string(wholesaleCost) + '\n';
	temp += "Retail Price: " + to_string(retailPrice);
	return temp;
}

ofstream &operator <<(ofstream &out, Book &book)
{
	out << book.ISBN << endl;
	out << book.title << endl;
	out << book.author << endl;
	out << book.publisher << endl;
	out << book.date << endl;
	out << book.quantity << endl;
	out << book.wholesaleCost << endl;
	out << book.retailPrice << endl;
	return out;
}

ifstream &operator >>(ifstream &in, Book &book)
{
	string tempStr;
	int tempNum;
	double tempDbl;

	getline(in, tempStr, '\n');
	book.ISBN = tempStr;
	getline(in, tempStr, '\n');
	book.title = tempStr;
	getline(in, tempStr, '\n');
	book.author = tempStr;
	getline(in, tempStr, '\n');
	book.publisher = tempStr;
	getline(in, tempStr, '\n');
	book.date = tempStr;

	getline(in, tempStr, '\n');
	tempNum = stoi(tempStr);
	book.quantity = tempNum;

	getline(in, tempStr, '\n');
	tempDbl = stod(tempStr);
	book.wholesaleCost = tempDbl;

	getline(in, tempStr, '\n');
	tempDbl = stod(tempStr);
	book.retailPrice = tempDbl;

	return in;
}