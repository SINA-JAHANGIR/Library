#include <iostream>
using namespace std;

#include <cstdlib>
#include <thread>
#include <chrono>

#include "Book.h"
#include "Node.h"
#include "User.h"
#include "Queue.h"
#include "AVL-Tree.h"

#define CLEAR system("cls")
#define WAIT this_thread::sleep_for(chrono::milliseconds(1300))

Node<Book>* books;
Node<User>* users;

int today;

void addBook(Book);
bool removeBook(string);
void addUser(User);
bool removeUser(string);
void signUp();
void signIn();
void userMenu();

int main()
{
	// Get today's date :

	cout << "ENTER TODAY'S DATE : ";
	int month, day;
	cin >> month >> day;
	today = (month - 1) * 30 + day;

	// Sign-up & Sign-in 

	while (true)
	{
		CLEAR;
		char input1;
		cout << "1. SIGN UP" << endl
			<< "2. SIGN IN" << endl
			<< "3. Exit" << endl;
		cin >> input1;
		switch (input1)
		{
		case '1':
			signUp();
			break;
		case '2':
			signIn();
			break;
		case '3':
			exit(1);
		default:
			cout << "INVALID ANSWER ! PLEASE TRY AGAIN .";
			WAIT;
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;
}

///////////////////////////////////////Functions///////////////////////////////////////

void addBook(Book input)
{
	Node<Book>* temp = new Node<Book>;
	temp->setValue(input);
	temp->setNext(books);
	books = temp;
}

bool removeBook(string t)
{
	if (books == nullptr)
		return false;

	Node<Book>* temp = books;
	if (books->getValue().getTitle() == t)
	{
		books = books->getNext();
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

void addUser(User input)
{
	Node<User>* temp = new Node<User>;
	temp->setValue(input);
	temp->setNext(users);
	users = temp;
}

bool removeUser(string u)
{
	if (users == nullptr)
		return false;

	Node<User>* temp = users;
	if (users->getValue().getUsername() == u)
	{
		users = users->getNext();
		delete temp;
		return true;
	}
	Node<User>* temp2 = nullptr;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNext()->getValue().getUsername() == u)
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

void signUp()
{
	CLEAR;
	string name, lastName, nationalCode, username, password;
	cout << "NAME : "; cin >> name;
	cout << endl << "LAST NAME : "; cin >> lastName;
	cout << endl << "NATIONAL CODE : "; cin >> nationalCode;
	cout << endl << "USERNAME : "; cin >> username;
	cout << endl << "PASSWORD : "; cin >> password;
	User temp(name, lastName, nationalCode, username, password);
	addUser(temp);
}

void signIn()
{
	CLEAR;
	string username, password;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "PASSWORD : "; cin >> password;
	AVLTree<User> userAVL(users);
	User* currentUser = new User();
	currentUser = userAVL.search(userAVL.root,username);
	if (currentUser == nullptr)
	{
		CLEAR;
		cout << "NOT FOUND !";
		WAIT;
	}
	else
	{
		if (currentUser->getPassword() == password)
			userMenu();
		else
		{
			CLEAR;
			cout << "INCORRECT PASSWORD !";
			WAIT;
		}
	}
}


void userMenu()
{
	// USER MENU :
}