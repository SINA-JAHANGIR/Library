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
User* currentUser = nullptr;

/*----------------------------*/
void addBook(Book*);
bool removeBook(string);
void addUser(User*);
bool removeUser(string);
/*----------------------------*/
void signUp();
void signIn();
/*----------------------------*/
void showAllBooks();
void showAllBooksSorted();
void showUserBooks(User);
void showUserBooksSorted(User);
void searchBook();
void userMenu();
/*----------------------------*/



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
		char input;
		cout << "1. SIGN UP" << endl
			<< "2. SIGN IN" << endl
			<< "3. Exit" << endl;
		cin >> input;
		switch (input)
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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	return 0;
}

/*-------------------------------------------Functions---------------------------------------------*/

void addBook(Book* input)
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
	if (books->getValue()->getTitle() == t)
	{
		books = books->getNext();
		delete temp;
		return true;
	}
	Node<Book>* temp2 = nullptr;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNext()->getValue()->getTitle() == t)
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

void addUser(User* input)
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
	if (users->getValue()->getUsername() == u)
	{
		users = users->getNext();
		delete temp;
		return true;
	}
	Node<User>* temp2 = nullptr;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNext()->getValue()->getUsername() == u)
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


/*----------------------------------------------------------------------------------------------------*/


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
	addUser(&temp);
}

void signIn()
{
	CLEAR;
	string username, password;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "PASSWORD : "; cin >> password;
	AVLTree<User> userAVL(users);
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


/*----------------------------------------------------------------------------------------------------*/


void showAllBooks()
{
	if (books == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
		return;
	}
	Node<Book>* temp = books;
	while (temp != nullptr)
	{
		temp->getValue()->print();
		temp = temp->getNext();
	}
}

void showAllBooksSorted()
{
	if (books == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
		return;
	}
	AVLTree<Book> bookAVL(books);
	bookAVL.inorder(bookAVL.get_root());
}

void showUserBooks(User user)
{
	if (user.getUserBooks() == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
		return;
	}
	Node<Book>* temp = user.getUserBooks();
	while (temp != nullptr)
	{
		temp->getValue()->print();
		temp = temp->getNext();
	}
}

void showUserBooksSorted(User user)
{
	if (user.getUserBooks() == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
		return;
	}
	Node<Book>* temp = user.getUserBooks();
	AVLTree<Book> userBooksAVL(temp);
	userBooksAVL.inorder(userBooksAVL.get_root());
}

void searchBook()
{
	cout << "ENTER YOUR BOOK TITLE : ";
	string title;
	cin >> title;
	AVLTree<Book> bookAVL(books);
	Book* temp = bookAVL.search(bookAVL.get_root(), title);
	CLEAR;
	if (temp == nullptr)
	{
		cout << "NOT FOUND !";
	}
	else
	{
		temp->print();
	}
}

void userMenu()
{
	bool flag = false;
	while (true)
	{
		CLEAR;
		char input;
		cout << "1. ALL BOOKS" << endl
			<< "2. ALL BOOKS (SORTED)" << endl
			<< "3. MY BOOKS" << endl
			<< "4. MY BOOKS (SORTED)" << endl
			<< "5. SEARCH" << endl
			<< "6. BACK" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			CLEAR;
			showAllBooks();
			WAIT;
			WAIT;
			WAIT;
			break;
		case '2':
			CLEAR;
			showAllBooksSorted();
			WAIT;
			WAIT;
			WAIT;
			break;
		case '3':
			CLEAR;
			showUserBooks(*currentUser);
			WAIT;
			WAIT;
			WAIT;
			break;
		case '4':
			CLEAR;
			showUserBooksSorted(*currentUser);
			WAIT;
			WAIT;
			WAIT;
			break;
		case '5':
			CLEAR;
			searchBook();
			WAIT;
			WAIT;
			WAIT;
			break;
		case '6':
			flag = true;
			break;
		default:
			cout << "INVALID ANSWER ! PLEASE TRY AGAIN .";
			WAIT;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		if (flag)
			break;
	}
}