#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Book
{
	friend class BookStore;

private:
	string ISBN; 
	string title;
	string author;
	string publisher;
	string date;
	int month;
	int day;
	int year;
	int quantity;
	double wholesaleCost;
	double retailPrice;

public:
	Book();
	Book(string, string, string, string, int, int, int, int, double, double);
    
	void setISBN(string);
	void setTitle(string);
	void setAuthor(string);
	void setPublisher(string);
	void setQuantity(int);
	void setWholesaleCost(double);
	void setRetailPrice(double);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	string getISBN() const;
	string getTitle() const;
	string getAuthor() const;
	string getPublisher() const;
	string getDate() const;
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	int getQuantity() const;
	double getWholesaleCost() const;
	double getRetailPrice() const;

	string toString();

	friend ofstream &operator <<(ofstream &, Book &);
	friend ifstream &operator >>(ifstream &, Book &);
};
#endif