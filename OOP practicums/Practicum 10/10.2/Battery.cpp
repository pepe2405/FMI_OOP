#include "Battery.h"

void Battery::free()
{
	delete[] batteryID;
	capacity = 0;
}

void Battery::copyFrom(const Battery& other)
{
	batteryID = other.batteryID;
	capacity = other.capacity;
}

void Battery::moveFrom(Battery&& other)
{
	batteryID = other.batteryID;
	batteryID = nullptr;
	capacity = 0;
}

Battery::Battery(const Battery& other) : CarPart(other)
{
	copyFrom(other);
}

Battery& Battery::operator=(const Battery& other)
{
	if (this != &other)
	{
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Battery::Battery(Battery&& other) noexcept : CarPart(std::move(other))
{
	moveFrom(std::move(other));
}

Battery& Battery::operator=(Battery&& other) noexcept
{
	if (this != &other)
	{
		CarPart::operator=(std::move(other));
		free();
		copyFrom(other);
	}
	return *this;
}

void Battery::setBatteryID(const char* newBatteryID)
{
	if (this->batteryID == nullptr)
		return;
	delete[] this->batteryID;
	const int len = strlen(newBatteryID) + 1;
	this->batteryID = new char[len];
	strcpy_s(this->batteryID, len, newBatteryID);
}

void Battery::setCapacity(unsigned newCapacity)
{
	this->capacity = newCapacity;
}

const char* Battery::getBatteryID() const
{
	return batteryID;
}

unsigned Battery::getCapacity() const
{
	return capacity;
}

Battery::Battery(const char* mFName, const char* descr, unsigned capacity, const char* batteryID) : CarPart(mFName, descr)
{
	setCapacity(capacity);
	setBatteryID(batteryID);
}


Battery::~Battery()
{
	free();
}

std::ostream& operator<<(std::ostream& os, const Battery& battery)
{
	return os << battery.getCurrId() << " by " <<
		battery.getMFName() << " - " <<
		battery.getDescr() << " - " <<
		battery.capacity << " Ah" << std::endl;
}










