#pragma once
#include "Flight.h"

class FlightSystem
{
	Flight** flights{};
	int capacity{};
	int count = 0;

	void free();
	void copyFrom(const FlightSystem& other);

	void resize(int newCap);
	void sort() const;

public:
	FlightSystem();
	FlightSystem(const FlightSystem& other);
	FlightSystem& operator=(const FlightSystem& other);
	~FlightSystem();
		
	void addFlight(const Flight& flight);
	void deleteFlight(unsigned id);
	const Flight& getFlight(unsigned id) const;
	void changeTOHour(unsigned id, unsigned newHour) const;
	int getCount() const;
	void print() const;
	void reserveFlight(unsigned id) const;
};