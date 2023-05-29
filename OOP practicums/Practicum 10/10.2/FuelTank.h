#pragma once
#include "CarPart.h"

class FuelTank : public CarPart
{
	double maxCapacity = 0;
	double currFuel = 0;

	void setMaxCapacity(double maxCapacity);

public:
	FuelTank(double maxCapacity);
	FuelTank() = default;

	double getCurrFuel() const;
	double getMaxCapacity() const;

	void useFuel(double amount);
	void pumpFuel(double amount);
};