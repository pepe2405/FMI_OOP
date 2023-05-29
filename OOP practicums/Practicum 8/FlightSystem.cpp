#include "FlightSystem.h"
#include <exception>
#include <iostream>

void FlightSystem::free()
{
	for (int i = 0; i < count; i++)
		delete flights[i];
	delete[] flights;
	count = 0;
	capacity = 0;
}

void FlightSystem::copyFrom(const FlightSystem& other)
{
	count = other.count;
	capacity = other.capacity;
	flights = new Flight* [capacity];
	for (int i = 0; i < count; i++)
	{
		if (other.flights[i] == nullptr)
			flights[i] = nullptr;
		else
			flights[i] = other.flights[i];
	}
}

void FlightSystem::resize(int newCap)
{
	Flight** newPtr = new Flight* [newCap] {nullptr};

	for (int i = 0; i < count; i++)
		newPtr[i] = flights[i];

	delete flights;
	flights = newPtr;

	capacity = newCap;
}

FlightSystem::FlightSystem()
{
	capacity = 8;
	flights = new Flight * [capacity] {nullptr};
}

FlightSystem::FlightSystem(const FlightSystem& other)
{
	copyFrom(other);
}

FlightSystem& FlightSystem::operator=(const FlightSystem& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

FlightSystem::~FlightSystem()
{
	free();
}

void FlightSystem::addFlight(const Flight& flight)
{
	if (count > capacity)
		resize(capacity * 2);

	flights[count++] = new Flight(flight);

}

void FlightSystem::deleteFlight(unsigned id)
{
	for (int i = 0; i < count; i++)
	{
		if (flights[i]->getId() == id)
		{
			flights[i] = nullptr;
			std::swap(flights[i], flights[count - 1]);
			if (count == capacity / 4)
				resize(capacity / 2);
			count--;

			return;
		}
	}
	throw std::exception("No such flight in the system!");
}

void FlightSystem::sort() const
{
	const int size = this->count;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (flights[j]->getTakeOfHour() > flights[j + 1]->getTakeOfHour() || flights[j] == nullptr)
				std::swap(flights[j], flights[j+1]);
		}
	}
}

const Flight& FlightSystem::getFlight(unsigned id) const
{
	for (int i = 0; i < count; i++)
	{
		if (flights[i]->getId() == id)
			return *flights[i];
	}
	throw std::exception("No such flight in the system!");
}

void FlightSystem::changeTOHour(unsigned id, unsigned newHour) const
{
	int size = this->count;
	for (int i = 0; i < size; i++)
	{
		if (flights[i]->getId() == id)
			flights[i]->setTOHour(newHour);
	}
	throw std::exception("No such flight in the system!");
}

void FlightSystem::print() const
{
	sort(); 

	for (int i = 0; i < count; i++)
	{
		std::cout << "Flight Nr: " << flights[i]->getId() << std::endl;
		std::cout << "From: " << flights[i]->getOrigin() << std::endl;
		std::cout << "To: " << flights[i]->getDest() << std::endl;
		std::cout << "Price: " << flights[i]->getPrice() << std::endl << std::endl;
	}
}

int FlightSystem::getCount() const
{
	return count;
}

void FlightSystem::reserveFlight(unsigned id) const
{
	for (int i = 0; i < count; i++)
	{
		if (flights[i]->getId() == id)
		{
			if (!flights[i]->isReserved())
				flights[i]->reserve();
			else
				throw std::exception("This flight is already reserved!");
		}
	}
	throw std::exception("No such flight in the system!");
}
			
