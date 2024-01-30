#pragma once

template <typename T>
class Node
{
private:
	T* value;
	Node* next;
public:
	void setValue(T*);
	void setNext(Node*);
	T* getValue();
	Node* getNext();
};

template <typename T>
void Node<T>::setValue(T* v)
{
	value = v;
}

template <typename T>
void Node<T>::setNext(Node* n)
{
	next = n;
}

template <typename T>
T* Node<T>::getValue()
{
	return value;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}