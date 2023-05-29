// ReSharper disable All
#include "Computer.h"

#include <cstring>
#include <exception>

void Computer::free()
{
	delete[] _gpuModel;
	for (int i = 0; i < _deviceCount; i++)
		delete[] devices[i];
	delete[] devices;
	_cpuPower = 0;
	_suplyPower = 0;
	_ram = 0;
	_deviceCount = 0;
}

void Computer::copyFrom(const Computer& other)
{
	devices = new char* [_deviceCount];
	for (int i = 0; i < _deviceCount; i++)
	{
		const int len = strlen(other.devices[i]) + 1;
		devices[i] = new char[len];
		strcpy_s(devices[i], len, other.devices[i]);
	}
	_cpuPower = other._cpuPower;
	_ram = other._ram;
	_deviceCount = other._deviceCount;
	_suplyPower = other._suplyPower;

	const int len = strlen(other._gpuModel) + 1;
	_gpuModel = new char[len];
	strcpy_s(_gpuModel, len, other._gpuModel);
}

void Computer::moveFrom(Computer&& other)
{
	devices = other.devices;
	other.devices = nullptr;
	_gpuModel = other._gpuModel;
	other._gpuModel = nullptr;
	_ram = other._ram;
	_suplyPower = other._suplyPower;
	_cpuPower = other._cpuPower;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Computer::Computer(Computer&& other) noexcept
{
	moveFrom(std::move(other));
}

Computer& Computer::operator=(Computer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setRam(int ram)
{
	if (ram < 0)
		throw std::exception("Invalid Ram!");
	_ram = ram;
}

void Computer::setCpuPower(double cpuPower)
{
	if (cpuPower < 0)
		throw std::exception("Invalid cpu power!");
	_cpuPower = cpuPower;
}

void Computer::setSuplyPower(int suplyPower)
{
	if (suplyPower < 0)
		throw std::exception("Invalid suply power!");
	_suplyPower = suplyPower;
}

void Computer::setGpuModel(const char* gpuModel)
{
	if (_gpuModel == nullptr)
		return;
	delete[] _gpuModel;
	const int len = strlen(gpuModel) + 1;
	_gpuModel = new char[len];
	strcpy_s(_gpuModel, len, gpuModel);
}

Computer::Computer(double cpuPower, const char* gpuModel, int suplyPower, int ram)
{
	setCpuPower(cpuPower);
	setGpuModel(gpuModel);
	setSuplyPower(suplyPower);
	setRam(ram);
}

double Computer::getCpuPower() const
{
	return _cpuPower;
}

const char* Computer::getGpuModel() const
{
	return _gpuModel;
}

int Computer::getRam() const
{
	return _ram;
}

int Computer::getSuplyPower() const
{
	return _suplyPower;
}







