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
	string username;
	string password;
	Node<Book>* userBooks;
public:
	User(string, string, string, string, string);
	User();
	void setName(string);
	void setLastName(string);
	void setNationalCode(string);
	void setUsername(string);
	void setPassword(string);
	string getName() const;
	string getLastName() const;
	string getNationalCode() const;
	string getUsername() const;
	string getPassword() const;
	User& operator=(const User&);
	bool operator<(const User&);
	bool operator>=(const User&);
	Node<Book>* getUserBooks() const;
	void addBook(Book*);
	bool removeBook(string);
};
