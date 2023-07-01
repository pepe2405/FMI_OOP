#pragma once
#include <algorithm>

template <typename T>
class Optional
{
	T* data = nullptr;

	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);
	void free();
public:
	Optional() = default;
	Optional(const T& obj);
	Optional(const Optional<T>& other);
	Optional& operator=(const Optional<T>& other);
	Optional(Optional<T>&& other) noexcept;
	Optional& operator=(Optional<T>&& other) noexcept;
	~Optional();

	void setData(const T& obj);
	bool containsData() const;
	const T& getData() const;
	void  clear();
	const T& operator*() const;
	T& operator*();
};

template <typename T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (other.containsData())
		data = new T(*data);
	else
		data = nullptr;
}

template <typename T>
void Optional<T>::moveFrom(Optional<T>&& other)
{
	data = other.data;
}

template <typename T>
void Optional<T>::free()
{
	delete data;
	data = nullptr;
}

template <typename T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template <typename T>
Optional<T>::Optional(Optional<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
Optional<T>::~Optional()
{
	free();
}

template <typename T>
Optional<T>::Optional(const T& obj)
{
	setData(obj);
}

template <typename T>
void Optional<T>::clear()
{
	free();
	data = nullptr;
}

template <typename T>
bool Optional<T>::containsData() const
{
	return data != nullptr;
}

template <typename T>
void Optional<T>::setData(const T& obj)
{
	delete data;
	data = new T(obj);
}

template <typename T>
const T& Optional<T>::getData() const
{
	if (!containsData())
		throw std::exception("No item");
	return *data;
}

template <typename T>
T& Optional<T>::operator*()
{
	if (!containsData())
		throw std::exception("No item");
	return *data;
}

template <typename T>
const T& Optional<T>::operator*() const
{
	if (!containsData())
		throw std::exception("No item");
	return *data;
}









