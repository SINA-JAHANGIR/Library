#pragma once

#include <iostream>
#include "Queue.h"
//#include "User.h"
using namespace std;

class Book
{
private:
	string title;
	string genre;
	string date;
	string author;
	bool available;
	int dateOfReturn;
	int dateOfAssign;
	Queue<pair<string, int>> reserve;
public:
	Book(string, string, string, string);
	Book();
	void setTitle(string);
	void setGenre(string);
	void setDate(string);
	void setAuthor(string);
	void setAvailable(bool);
	void setDateOfReturn(int);
	void setDateOfAssign(int);
	string getTitle() const;
	string getGenre() const;
	string getDate() const;
	string getAuthor() const;
	bool getAvailable() const;
	int getDateOfReturn() const;
	int getDateOfAssign() const;
	Book& operator=(const Book&);
	bool operator<(const Book&);
	bool operator>=(const Book&);
	void print();
	void addReservation(string);
	void removeReservation(int);
	bool checkReservation(string, int);
	void updateI();
	int getSizeReserve();
};