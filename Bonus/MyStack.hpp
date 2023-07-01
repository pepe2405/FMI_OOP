#pragma once
#include <exception>

template <typename T, const int S>
class MyStack
{
	T data[S];
	int size = 0;
public:
	MyStack() = default;
	void push(const T& obj);
	void push(T&& obj);
	void pop();
	const T& peek() const;
	bool isEmpty() const;
};

template <typename T, const int S>
void MyStack<T, S>::push(T&& obj)
{
	if (size >= S)
		throw std::exception("No capacity left");
	data[size++] = obj;
}

template <typename T, const int S>
void MyStack<T, S>::push(const T& obj)
{
	if (size >= S)
		throw std::exception("No capacity left");
	data[size++] = std::move(obj);
}

template <typename T, const int S>
const T& MyStack<T, S>::peek() const
{
	if (isEmpty())
		throw std::exception("Nothing in the stack");
	return data[size - 1];
}

template <typename T, const int S>
void MyStack<T, S>::pop()
{
	if (isEmpty())
		throw std::exception("Nothing in the stack");
	size--;
}

template <typename T, const int S>
bool MyStack<T, S>::isEmpty() const
{
	return size == 0;
}






