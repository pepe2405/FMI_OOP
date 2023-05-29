#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
public:
	GamingConsole(double cpuPower, const char* gpuModel, int suplyPower, int ram);

	void printType() const override;
	void printDevices() const override;
};
