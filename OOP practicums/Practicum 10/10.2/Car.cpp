#include "Car.h"

Car::Car(const FuelTank& ft, const Engine& en, const Tire& t, const Battery& b, double weight)
{
	_ft = ft;
	_en = en;
	_t = t;
	_b = b;
	_distanceTraveled = 0;
	_weight = weight;
}

void Car::drive(double km)
{
	if (km < 0)
		throw std::logic_error("Km can't be negative!");
	if (_ft.getCurrFuel() < 0.00001)
		return;
	_ft.useFuel(km);
	_distanceTraveled += km;
}

