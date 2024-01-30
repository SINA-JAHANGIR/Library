#include "Book.h"

Book::Book(string t, string g, string d, string a)
{
	title = t; genre = g; date = d; author = a;
}

Book::Book()
{
	title = genre = date = author = "";
}

void Book::setTitle(string input)
{
	title = input;
}

void Book::setGenre(string input)
{
	genre = input;
}

void Book::setDate(string input)
{
	date = input;
}

void Book::setAuthor(string input)
{
	author = input;
}

string Book::getTitle() const
{
	return this->title;
}

string Book::getGenre() const
{
	return this->genre;
}

string Book::getDate() const
{
	return this->date;
}

string Book::getAuthor() const
{
	return this->author;
}

Book& Book::operator=(const Book& other)
{
	this->title = other.getTitle();
	this->genre = other.getGenre();
	this->date = other.getDate();
	this->author = other.getAuthor();
	return *this;
}

bool Book::operator<(const Book& other)
{
	if (title < other.getTitle())
		return true;
	else
		return false;
}

bool Book::operator>=(const Book& other)
{
	if (title < other.getTitle())
		return false;
	else
		return true;
}

void Book::print()
{
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "Title : " << title << endl <<
		"Author : " << author << endl <<
		"Genre : " << genre << "		" << date << endl;
	cout << "---------------------------------------";
	cout << endl;
}