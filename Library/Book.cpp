#include "Book.h"

Book::Book(string t, string g, string d, string a)
{
	title = t; genre = g; date = d; author = a; available = true; dateOfReturn = -1;
}

Book::Book()
{
	title = genre = date = author = "";
	available = true;
	dateOfReturn = -1;
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

void Book::setAvailable(bool input)
{
	available = input;
}

void Book::setDateOfReturn(int input)
{
	dateOfReturn = input;
}

void Book::setDateOfAssign(int input)
{
	dateOfAssign = input;
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

bool Book::getAvailable() const
{
	return this->available;
}

int Book::getDateOfReturn() const
{
	return this->dateOfReturn;
}

int Book::getDateOfAssign() const
{
	return this->dateOfAssign;
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

void Book::addReservation(string username, int date)
{

	reserve.enqueue(make_pair(username, date));
}

void Book::removeReservation(int today)
{
	pair<string, int> temp;
	temp = reserve.getFirstElement();
	while (today - dateOfReturn > 3 && temp.first!= "")
	{
		reserve.dequeue();
		temp = reserve.getFirstElement();
	}
}

bool Book::checkReservation(string username, int today)
{
	removeReservation(today);
	pair<string, int> temp;
	temp = reserve.getFirstElement();
	if (reserve.getSize() == 0 || temp.first == username)
	{
		if (temp.first == username)
		{
			reserve.dequeue();
		}
		return true;
	}
	else
		return false;
}