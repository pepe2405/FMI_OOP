#include "User.h"

#include <exception>
#include <iostream>

#include "FlightSystem.h"

User::User()
{
	price = 0;
	reservedCount = 0;
}

void User::reserveFlight(const FlightSystem& fs, int id)
{
	if (reservedCount == 64)
		throw std::exception("Unable to reserve more flights");
	fs.reserveFlight(id);
	reservedIds[reservedCount++] = id;
}

void User::printFlights() const
{
	std::cout << "The ids of the reserved flights are: ";
	for (int i = 0; i < reservedCount - 1; i++)
	{
		std::cout << reservedIds[i] << ' ';
	}
}
