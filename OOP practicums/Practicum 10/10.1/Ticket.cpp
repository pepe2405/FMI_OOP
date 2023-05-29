#include "Ticket.h"
#include <cstring>
#include <iostream>

Ticket::Ticket(const char* name, double price)
{
	strcpy_s(this->name, strlen(name + 1), name);
	this->price = price;
}

void Ticket::copyFrom(const Ticket& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, name);
	price = other.price;
}

void Ticket::free()
{
	delete[] name;
	price = 0;
}

void Ticket::moveFrom(Ticket&& other)
{
	name = other.name;
	other.name = nullptr;
	price = other.price;
}

Ticket::Ticket(const Ticket& other)
{
	copyFrom(other);
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Ticket::Ticket(Ticket&& other) noexcept
{
	moveFrom(std::move(other));
}

Ticket& Ticket::operator=(Ticket&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Ticket::print() const
{
	std::cout << "Name: " << name << " Price: " << price << std::endl;
}

Ticket::~Ticket()
{
	free();
}








