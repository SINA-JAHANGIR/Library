#pragma once

#include <iostream>
using namespace std;

#include "Node.h"
#include "Book.h"

class User
{
private:
	string name;
	string lastName;
	string nationalCode;
	string userName;
	string password;
	Node<Book>* userBooks;
public:
	User(string, string, string, string, string);
	User();
	void setName(string);
	void setLastName(string);
	void setNationalCode(string);
	void setUserName(string);
	void setPassword(string);
	string getName() const;
	string getLastName() const;
	string getNationalCode() const;
	string getUserName() const;
	string getPassword() const;
	User& operator=(const User&);
	Node<Book>* getUserBooks();
	void addBook(Book);
	bool removeBook(string);
};
