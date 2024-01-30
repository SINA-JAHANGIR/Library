#include <iostream>
using namespace std;

#include "Book.h"
#include "Node.h"
#include "User.h"
#include "AVL-Tree.h"

Node<Book>* books;
Node<User>* users;

void addBook(Book);
bool removeBook(string);
void addUser(User);
bool removeUser(string);
Book searchBook(string);
void showAllBooks();
void showAllbooksSorted();
void showUserBooks(User);
void showUserBooksSorted(User);

int main()
{
	cout << "Hello from library !";

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
	if (users->getValue().getUserName() == u)
	{
		users = users->getNext();
		delete temp;
		return true;
	}
	Node<User>* temp2 = nullptr;
	while (temp->getNext() != nullptr)
	{
		if (temp->getNext()->getValue().getUserName() == u)
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

Book searchBook(string title) 
{
	AVLTree<Book> bookAVL(books);
	return bookAVL.search(bookAVL.get_root(), title);
}

void showAllBooks()
{
	Node<Book>* temp = books;
	if (temp == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
	}
	while (temp != nullptr)
	{
		temp->getValue().print();
		temp = temp->getNext();
	}
}

void showAllbooksSorted()
{
	AVLTree<Book> bookAVL(books);
	bookAVL.inorder(bookAVL.get_root());
}

void showUserBooks(User user)
{
	Node<Book>* temp = user.getUserBooks();
	if (temp == nullptr)
	{
		cout << "THERE ARE NO BOOKS !" << endl;
	}
	while (temp != nullptr)
	{
		temp->getValue().print();
		temp = temp->getNext();
	}
}

void showUserBooksSorted(User user)
{
	Node<Book>* temp = user.getUserBooks();
	AVLTree<Book> userBooksAVL(temp);
	userBooksAVL.inorder(userBooksAVL.get_root());
}