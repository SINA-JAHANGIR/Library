#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	static const int MAX = 13;
	int size;
	int front;
	int rear;
	int i;
	T queue[MAX];
public:
	Queue();
	void setI(int);
	int getI();
	int getSize();
	void enqueue(T);
	T dequeue();
	T getFirstElement();
};

template<typename T>
Queue<T>::Queue()
{
	size = rear = front = i = 0;
}

template<typename T>
void Queue<T>::setI(int input)
{
	i = input;
}

template<typename T>
int Queue<T>::getI()
{
	return i;
}

template<typename T>
int Queue<T>::getSize()
{
	return size;
}

template <typename T>
void Queue<T>::enqueue(T input)
{
	if (size == MAX)
		throw exception("queue is full !");
	queue[rear] = input;
	rear = (rear + 1) % MAX;
	size++;
	i++;
}

template<typename T>
T Queue<T>::dequeue()
{
	if (size == 0)
		throw exception("queue is empty !");
	T temp = queue[front];
	front = (front + 1) % MAX;
	size--;
	return temp;
}

template<typename T>
T Queue<T>::getFirstElement()
{
	return queue[front];
}
