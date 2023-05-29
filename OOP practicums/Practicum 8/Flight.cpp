#include "Flight.h"
#include <cstring>
#include <exception>

unsigned Flight::createdFlights = 0;

bool Flight::isValidString(const char* str) const
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' '))
			return false;
	}
	return true;
}

void Flight::setDest(const char* newDest)
{
	if (!isValidString(newDest))
		throw std::exception("Invalid string!");
	strcpy_s(this->dest, strlen(newDest) + 1, newDest);
}

void Flight::setOrigin(const char* newOrigin)
{
	if (!isValidString(newOrigin))
		throw std::exception("Invalid string!");
	strcpy_s(this->origin, strlen(newOrigin) + 1, newOrigin);
}

void Flight::setTOHour(unsigned newHour)
{
	if (newHour > 24)
		throw std::exception("Invalid hour!");
	this->takeOffHour = newHour;
}

Flight::Flight(const char* origin, const char* dest, double price, int takeOffHour)
{
	setOrigin(origin);
	setDest(dest);
	this->price = price;
	setTOHour(takeOffHour);
	reserved = false;
	createdFlights++;
	id = createdFlights;
}

Flight::Flight() : Flight("Unknown", "Unknown", 0, 0) {}

int Flight::getId() const
{
	return id;
}

int Flight::getTakeOfHour() const
{
	return takeOffHour;
}

bool Flight::isReserved() const
{
	return reserved;
}

const char* Flight::getDest() const
{
	return dest;
}

const char* Flight::getOrigin() const
{
	return origin;
}

double Flight::getPrice() const
{
	return price;
}

void Flight::reserve()
{
	this->reserved = !reserved;
}







