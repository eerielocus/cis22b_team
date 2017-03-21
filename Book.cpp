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
	date = string(2 - to_string(month).length(), '0') + to_string(month) + "/" + string(2 - to_string(day).length(), '0') + to_string(day) + "/" + to_string(year);
	quantity = q;
	wholesaleCost = c;
	retailPrice = r;
}

// Function to convert double with proper precision out to string. string(2 - to_string(month).length(), '0')
template <typename T>
string Book::to_string_prec(const T a_value)
{
	ostringstream out;
	out << setprecision(2) << fixed << a_value;
	return out.str();
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

void Book::setDate(int m, int d, int y)
{
	date = to_string(m) + "/" + to_string(d) + "/" + to_string(y);
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

// Easy to call string output method.
string Book::toString()
{
	string temp;
	temp += "ISBN: " + ISBN + '\n';
	temp += "Title: " + title + '\n';
	temp += "Author: " + author + '\n';
	temp += "Publisher: " + publisher + '\n';
	temp += "Date Added: " + date + '\n';
	temp += "Quantity: " + to_string(quantity) + '\n';
	temp += "Wholesale Cost: " + to_string_prec(wholesaleCost) + '\n';
	temp += "Retail Price: " + to_string_prec(retailPrice);
	return temp;
}

// Operator overloading for both reading  of and writing to file.
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
	string tempStr, tempCo;
	int tempNum;
	double tempDbl;

	getline(in, tempStr, '\n');

	if (tempStr == "")
		return in;

	book.ISBN = tempStr;
	getline(in, tempStr, '\n');
	book.title = tempStr;
	getline(in, tempStr, '\n');
	book.author = tempStr;
	getline(in, tempStr, '\n');
	book.publisher = tempStr;
	getline(in, tempStr, '\n');
	book.date = tempStr;

	// Parse through date string and place into appropriate variables.
	tempCo = tempStr.substr(0, tempStr.find("/", 0));
	tempStr = tempStr.substr(tempStr.find("/", 0) + 1, tempStr.length());
	book.month = stoi(tempCo);
	tempCo = tempStr.substr(0, tempStr.find("/", 0));
	tempStr = tempStr.substr(tempStr.find("/", 0) + 1, tempStr.length());
	book.day = stoi(tempCo);
	book.year = stoi(tempStr);

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