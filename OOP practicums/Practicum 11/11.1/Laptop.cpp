#include "Laptop.h"

#include <iostream>

Laptop::Laptop(double cpuPower, const char* gpuModel, int suplyPower, int ram)
	: Computer(cpuPower, gpuModel, suplyPower, ram)
{
	_deviceCount = 4;
	// TODO: The devices to be described in the array  
}

void Laptop::printType() const
{
	std::cout << "This is a Laptop";
}

void Laptop::printDevices() const
{
	for (int i = 0; i < _deviceCount; i++)
	{
		// TODO: Print the devices
	}
}

