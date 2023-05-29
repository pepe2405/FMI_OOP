#pragma once
#include "Computer.h"

class Laptop : public Computer
{
public:
	Laptop(double cpuPower, const char* gpuModel, int suplyPower, int ram);

	void printType() const override;
	void printDevices() const override;
};
