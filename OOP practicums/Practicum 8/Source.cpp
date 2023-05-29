#include <iostream>
#include "Flight.h"
#include "FlightSystem.h"

int main()
{
	const Flight f1("Varna", "Sofia", 100, 5);
	const Flight f2("Varna", "Belgrad", 100, 4);
	const Flight f3("Varna", "Munchen", 100, 3);

	FlightSystem fs;
	fs.addFlight(f1);
	fs.addFlight(f2);
	fs.addFlight(f3);
	fs.deleteFlight(2);
	fs.print();
}