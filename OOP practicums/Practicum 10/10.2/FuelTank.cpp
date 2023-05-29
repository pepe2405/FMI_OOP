#include "FuelTank.h"

void FuelTank::setMaxCapacity(double newMaxCapacity)
{
	if (newMaxCapacity < 0)
		throw std::logic_error("Capacity can't be negative!");
	maxCapacity = newMaxCapacity;
}

double FuelTank::getCurrFuel() const
{
	return currFuel;
}

double FuelTank::getMaxCapacity() const
{
	return maxCapacity;
}

void FuelTank::pumpFuel(double amount)
{
	if (amount < 0)
		throw std::logic_error("Can't pump negative amount!");
	currFuel += amount;
	if (currFuel > maxCapacity)
		currFuel = maxCapacity;
}

void FuelTank::useFuel(double amount)
{
	if (amount < 0)
		throw std::logic_error("Can't use negative amount!");
	currFuel -= amount;
	if (currFuel < 0)
		throw std::logic_error("Can't use more fuel than the current amount in the tank!");
}

FuelTank::FuelTank(double maxCapacity)
{
	this->maxCapacity = maxCapacity;
	this->currFuel = maxCapacity;
}
