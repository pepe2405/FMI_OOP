#include "PC.h"

#include <iostream>

PC::PC(double cpuPower, const char* gpuModel, int suplyPower, int ram)
	: Computer(cpuPower, gpuModel, suplyPower, ram)
{
	_deviceCount = 4;
	// TODO: The devices to be described in the array  
}

void PC::printType() const
{
	std::cout << "This is a PC";
}

void PC::printDevices() const
{
	for (int i = 0; i < _deviceCount; i++)
	{
		// TODO: Print the devices
	}
}

