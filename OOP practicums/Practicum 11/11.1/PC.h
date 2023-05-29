#pragma once
#include "Computer.h"

class PC : public Computer
{
public:
	PC(double cpuPower, const char* gpuModel, int suplyPower, int ram);

	void printType() const override;
	void printDevices() const override;
};