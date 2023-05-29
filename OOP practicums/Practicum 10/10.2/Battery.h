#pragma once
#include "CarPart.h"

class Battery : public CarPart
{
	unsigned capacity = 0;
	char* batteryID = nullptr;
	void setCapacity(unsigned capacity);
	void setBatteryID(const char* batteryID);

	void free();
	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other);

public:
	Battery() = default;
	Battery(const char* mFName, const char* descr, unsigned capacity, const char* batteryID);

	Battery(const Battery& other);
	Battery& operator=(const Battery& other);

	Battery(Battery&& other) noexcept;
	Battery& operator=(Battery&& other) noexcept;

	~Battery();

	const char* getBatteryID() const;
	unsigned getCapacity() const;
	friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
};