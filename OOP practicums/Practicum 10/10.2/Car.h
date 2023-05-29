#pragma once
#include "CarPart.h"
#include "FuelTank.h"
#include "Tire.h"
#include "Battery.h"
#include "Engine.h"

class Car
{
	FuelTank _ft;
	Engine _en;
	Tire _t;
	Battery _b;
	double _distanceTraveled = 0;
	double _weight = 0;

public:
	Car(const FuelTank& ft, const Engine& en, const Tire& t, const Battery& b, double weight);
	void drive(double km);
};