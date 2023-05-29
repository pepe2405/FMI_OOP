#pragma once
#include "FlightSystem.h"

class User
{
	int reservedIds[64]{}; // 64 max reserved flights
	int price;
	int reservedCount;
public:
	User();
	void reserveFlight(const FlightSystem& fs, int id);
	void printFlights() const;
};
