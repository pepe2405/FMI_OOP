#pragma once
#include <algorithm>

template <typename T>
class MyQueue
{
	T* data;
	int size = 0;
	int capacity = 0;
	int put = 0;
	int get = 0;

	void copyFrom(const MyQueue<T>& other);
	void moveFrom(MyQueue<T>&& other);
	void free();

	void resize(int newCap);
public:
	MyQueue();
	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);
	MyQueue(MyQueue<T>&& other);
	MyQueue<T>& operator=(MyQueue<T>&& other);
	~MyQueue();

	void push(const T& obj);
	void push(T&& obj);
	const T& peek() const;
	void pop();
	bool isEmpty() const;
};

template <typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	get = 0;
	put = 0;
	size = 0;
	data = new T[4];
}

template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	delete[] data;
	data = new T[other.capacity];
	for (int i = 0; i < other.size; i++)
		data[i] = other.data[i];
	get = other.get;
	put = other.put;
	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	data = other.data;
	other.data = nullptr;
	put = other.put;
	get = other.get;
	capacity = other.capacity;
	size = other.size;
}

template <typename T>
void MyQueue<T>::free()
{
	delete[] data;
	get = 0;
	put = 0;
	size = 0;
	capacity = 0;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
void MyQueue<T>::push(const T& obj)
{
	if (size == capacity)
		resize(capacity * 2);
	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity)
		resize(capacity * 2);
	data[put] = std::move(obj);
	(++put) %= capacity;
	size++;
}

template <typename T>
const T& MyQueue<T>::peek() const
{
	if (isEmpty())
		throw std::exception("Nothing in the queue");
	return data[get];
}

template <typename T>
void MyQueue<T>::pop()
{
	if (isEmpty())
		throw std::exception("Nothing in the queue");
	(++get) %= capacity;
	size--;
	if (size == capacity / 4)
		resize(capacity / 2);
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
void MyQueue<T>::resize(int newCap)
{
	T* copy = new T[newCap];
	for (int i = 0; i < newCap; i++)
	{
		copy[i] = data[get];
		(++get) %= capacity;
	}
	delete[] data;
	data = copy;
	delete[] copy;
	capacity = newCap;
	get = 0;
	put = size;
}

template <typename T>
MyQueue<T>::~MyQueue()
{
	free();
}
