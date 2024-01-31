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
void insertUser(User*);
bool removeUser(string);
void signUp();
void signIn();
void signUpInMenu();
/*----------------------------*/
void showAllBooks();
void showAllBooksSorted();
void showUserBooks(User);
void showUserBooksSorted(User);
void searchBook();
void userMenu();
/*----------------------------*/
User* searchUser(string);
void assignBook();
void getBook();
void reserveBook();
void insertBook(Book*);
bool removeBook(string);
void addBook();
void deleteBook();
void adminMenu();
/*----------------------------*/



int main()
{

	while (true)
	{
		CLEAR;
		today = 0;
		currentUser = nullptr;
		cout << "ENTER TODAY'S DATE : ";
		int month, day;
		cin >> month >> day;
		today = (month - 1) * 30 + day;

		signUpInMenu();
	}

	return 0;
}

/*--------------------------------------------Functions------------------------------------------------*/

void insertUser(User* input)
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

void signUp()
{
	CLEAR;
	string name, lastName, nationalCode, username, password;
	cout << "NAME : "; cin >> name;
	cout << endl << "LAST NAME : "; cin >> lastName;
	cout << endl << "NATIONAL CODE : "; cin >> nationalCode;
	cout << endl << "USERNAME : "; cin >> username;
	cout << endl << "PASSWORD : "; cin >> password;
	User* temp = new User(name, lastName, nationalCode, username, password);
	insertUser(temp);
}

void signIn()
{
	CLEAR;
	string username, password;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "PASSWORD : "; cin >> password;
	if (username == "admin" && password == "1234")
	{
		adminMenu();
		return;
	}
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


void signUpInMenu()
{
	bool flag = false;
	while (true)
	{
		CLEAR;
		char input;
		cout << "1. SIGN UP" << endl
			<< "2. SIGN IN" << endl
			<< "3. BACK" << endl
			<< "4. Exit" << endl;
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
			flag = true;
			break;
		case '4':
			exit(1);
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


/*----------------------------------------------------------------------------------------------------*/

User* searchUser(string username)
{
	AVLTree<User> userAVL(users);
	return userAVL.search(userAVL.get_root(), username);
}

void assignBook()
{
	string username, title;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "TITLE : "; cin >> title;
	CLEAR;
	User* user = searchUser(username);
	AVLTree<Book> bookAVL(books);
	Book* book = bookAVL.search(bookAVL.get_root(), title);

	if (user == nullptr)
	{
		cout << "USER NOT FOUND !";
		WAIT;
	}
	else if (book == nullptr)
	{
		cout << "BOOK NOT FOUND !";
		WAIT;
	}
	else if (book->getAvailable() == false)
	{
		cout << "THIS BOOK IS NOT AVAILABLE !";
		WAIT;
	}
	else if (!book->checkReservation(user->getUsername(),today))
	{
		cout << "THIS BOOK IS RESERVED !";
		WAIT;
	}
	else
	{
		user->insertBook(book);
		book->setAvailable(false);
		book->setDateOfAssign(today);
	}
}

void getBook() 
{
	string username, title;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "TITLE : "; cin >> title;
	CLEAR;
	User* user = searchUser(username);
	if (user == nullptr)
	{
		cout << "USER NOT FOUND !" << endl;
		WAIT;
		return;
	}
	AVLTree<Book> bookAVL(user->getUserBooks());
	Book* book = bookAVL.search(bookAVL.get_root(), title);
	if (book == nullptr)
	{
		cout << "BOOK NOT FOUND !" << endl;
	}
	else
	{
		user->removeBook(title);
		book->setAvailable(true);
		book->setDateOfReturn(today);
		int temp = today - book->getDateOfAssign();
		if (temp > 10)
		{
			cout << "LATE PAYMENT PENALTY : " << (temp - 10) * 5 << "$";
		}
		else
			cout << "LATE PAYMENT PENALTY : 0$";
	}
	WAIT;
}

void reserveBook()
{
	string username, title;
	cout << "USERNAME : "; cin >> username;
	cout << endl << "TITLE : "; cin >> title;
	CLEAR;
	User* user = searchUser(username);
	AVLTree<Book> bookAVL(books);
	Book* book = bookAVL.search(bookAVL.get_root(), title);
	if (user == nullptr)
	{
		cout << "USER NOT FOUND !";
		WAIT;
	}
	else if (book == nullptr)
	{
		cout << "BOOK NOT FOUND !";
		WAIT;
	}
	else if (book->getAvailable() == true)
	{
		cout << "THIS BOOK IS AVAILABLE !" << endl
			<< "YOU CAN GET IT !";
		WAIT;
	}
	else
	{
		book->addReservation(user->getUsername(), today);
	}
}

void insertBook(Book* input)
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

void addBook()
{
	string title, genre, author, date;
	cout << "TITLE : "; cin >> title;
	cout << endl << "AUTHOR : "; cin >> author;
	cout << endl << "GENRE : "; cin >> genre;
	cout << endl << "PUBLICATION DATE : "; cin >> date;
	Book* temp = new Book(title, genre, date, author);
	insertBook(temp);
}

void deleteBook()
{
	string title;	
	cout << "TITLE : "; cin >> title;
	CLEAR;
	if (removeBook(title))
	{
		cout << "THE BOOK WAS SUCCESSFULLY REMOVED .";
	}
	else
	{
		cout << "NOT FOUND !";

	}
}

void adminMenu()
{
	bool flag = false;
	while (true)
	{
		CLEAR;
		char input;
		cout << "1. ASSIGN A BOOK" << endl
			<< "2. GET A BOOK" << endl
			<< "3. RESERVE A BOOK" << endl
			<< "4. EXTEND TIME" << endl
			<< "5. ADD A BOOK" << endl
			<< "6. REMOVE A BOOK" << endl
			<< "7. BACK" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			CLEAR;
			assignBook();
			break;
		case '2':
			CLEAR;
			getBook();
			break;
		case '3':
			CLEAR;
			reserveBook();
			break;
		case '4':
			
			break;
		case '5':
			CLEAR;
			addBook();
			break;
		case '6':
			CLEAR;
			deleteBook();
			WAIT;
			break;
		case '7':
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

/*----------------------------------------------------------------------------------------------------*/

