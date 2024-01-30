#pragma once

#include <iostream>
using namespace std;

class Book
{
private:
	string title;
	string genre;
	string date;
	string author;
public:
	Book(string, string, string, string);
	Book();
	void setTitle(string);
	void setGenre(string);
	void setDate(string);
	void setAuthor(string);
	string getTitle() const;
	string getGenre() const;
	string getDate() const;
	string getAuthor() const;
	Book& operator=(const Book&);
	bool operator<(const Book&);
	bool operator>=(const Book&);
	void print();
};