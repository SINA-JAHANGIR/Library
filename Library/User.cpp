#include "User.h"

User::User(string n, string l, string c, string u, string p)
{
	name = n; lastName = l; nationalCode = c; userName = u; password = p;
	userBooks = nullptr;
}

User::User()
{
	name = userName = nationalCode = userName = password = "";
}

void User::setName(string input)
{
	name = input;
}

void User::setLastName(string input)
{
	lastName = input;
}

void User::setNationalCode(string input)
{
	nationalCode = input;
}

void User::setUserName(string input)
{
	userName = input;
}

void User::setPassword(string input)
{
	password = input;
}

string User::getName() const
{
	return name;
}

string User::getLastName() const
{
	return lastName;
}

string User::getNationalCode() const
{
	return nationalCode;
}

string User::getUserName() const
{
	return userName;
}

string User::getPassword() const
{
	return password;
}

User& User::operator=(const User& other)
{
	this->name = other.getName();
	this->lastName = other.getLastName();
	this->nationalCode = other.getNationalCode();
	this->userName = other.getUserName();
	this->password = other.getPassword();
	return *this;
}

Node<Book>* User::getUserBooks()
{
	return userBooks;
}

void User::addBook(Book input)
{
	Node<Book>* temp = new Node<Book>;
	temp->setValue(input);
	temp->setNext(userBooks);
	userBooks = temp;
}

bool User::removeBook(string t)
{
	if (userBooks == nullptr)
		return false;

	Node<Book>* temp = userBooks;
	if (userBooks->getValue().getTitle() == t)
	{
		userBooks = userBooks->getNext();
		delete temp;
		return true;
	}
	Node<Book>* temp2 = nullptr;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNext()->getValue().getTitle() == t)
		{
			temp2 = temp->getNext();
			temp->setNext(temp->getNext()->getNext());
			delete temp2;
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}