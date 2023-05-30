#include "MyVector.h"

#include <algorithm>

template <typename T>
void MyVector<T>::free()
{
	for (int i = 0; i < _count; i++)
		delete _data[i];
	delete[] _data;
	_count = 0;
	_capacity = 0;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector& other)
{
	_count = other._count;
	_capacity = other._capacity;

	_data = new T * [_capacity];

	for (int i = 0; i < _count; i++)
	{
		if (other._data[i] == nullptr)
			_data[i] = nullptr;
		else
			_data[i] = new T(other._data[i]);
	}
}

template <typename T>
void MyVector<T>::moveFrom(MyVector&& other)
{
	_data = other._data;
	other._data = nullptr;
	_count = other._count;
	other._data = 0;
	_capacity = other._capacity;
	other._capacity = 0;
}

template <typename T>
void MyVector<T>::resize(unsigned newCapacity)
{
	T** newData = new T * [newCapacity] {nullptr};

	for (int i = 0; i < _count; i++)
		newData[i] = _data[i];
	delete[] _data;
	_data = newData;
	_capacity = newCapacity;
}

template <typename T>
MyVector<T>::MyVector()
{
	_capacity = 8;
	_count = 0;
	_data = new T * [_capacity] {nullptr};
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

template <typename T>
void MyVector<T>::pushBack(const T& element)
{
	if (_count > _capacity)
		resize(_capacity * 2);

	_data[_count++] = new T(element);
}

template <typename T>
void MyVector<T>::pushBack(T&& element)
{
	if (_count > _capacity)
		resize(_capacity * 2);

	_data[_count++] = new T(std::move(element));
}

template <typename T>
void MyVector<T>::popBack(const T& element)
{
	if (_count == 0)
		return;

	delete _data[_count - 1];
	_data[_count--] = nullptr;
	if (_count == _capacity / 4)
		resize(_capacity / 2);
}

template <typename T>
void MyVector<T>::insert(const T& element, unsigned index)
{
	if (index > _count - 1)
		throw std::exception("Invalid index!");
	if (_count == _capacity)
		resize(_capacity * 2);

	for (int i = _count - 1; i >= index; i--)
	{
		std::swap(_data[i], _data[i - 1]);
	}
	_data[index] = new T(element);
	_count++;
}

template <typename T>
void MyVector<T>::insert(T&& element, unsigned index)
{
	if (index > _count - 1)
		throw std::exception("Invalid index!");
	if (_count == _capacity)
		resize(_capacity * 2);

	for (int i = _count - 1; i >= index; i--)
	{
		std::swap(_data[i], _data[i - 1]);
	}
	_data[index] = new T(std::move(element));
	_count++;
}

template <typename T>
void MyVector<T>::erase(unsigned index)
{
	if (index > _count - 1)
		throw std::exception("Invalid index!");

	for (int i = index; i < _count - 2; i++)
	{
		std::swap(_data[i], _data[i + 1]);
	}
	delete _data[_count - 1];
	_data[_count - 1] = nullptr;
	_count--;

	if (_count == _capacity / 4)
		resize(_capacity / 2);
}

template <typename T>
void MyVector<T>::clear()
{
	free();
}

template <typename T>
unsigned MyVector<T>::size() const
{
	return _count;
}

template <typename T>
const T& MyVector<T>::operator[](unsigned index) const
{
	return *_data[index];
}

template <typename T>
T& MyVector<T>::operator[](unsigned index)
{
	return *_data[index];
}









