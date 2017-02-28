#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include "Date.h"

using namespace std;



class Book
{
private:
	string ISBN; 
	string bookTitle;
	string authorName;
	string publisher;
	Date date;
	int quantity;
	double wholesaleCost;
	double retailCost;

public:
	Book();
	Book(string, string, string, string, int, int, int, int, double, double);
    
	void setISBN(string);
	void setBookTitle(string);
	void setAuthorName(string);
	void setPublisher(string);
	void setQuantity(int);
	void setWholesaleCost(double);
	void setRetailCost(double);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	string getISBN() const;
	string getBookTitle() const;
	string getAuthorName() const;
	string getPublisher() const;
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	Date getDate() const;
	int getQuantity() const;
	double getWholesaleCost() const;
	double getRetailCost() const;

	string toString(int);
};
#endif