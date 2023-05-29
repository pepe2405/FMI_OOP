#include "CarPart.h"

unsigned CarPart::id = 0;

void CarPart::free()
{
	delete[] description;
	delete[] manufacturerName;
	currId = 0;
}

void CarPart::copyFrom(const CarPart& other)
{
	description = new char[strlen(other.description) + 1];
	description = other.description;
	manufacturerName = new char[strlen(other.description) + 1];
	manufacturerName = other.description;
	currId = other.currId;
}

void CarPart::moveFrom(CarPart&& other)
{
	description = other.description;
	other.description = nullptr;
	manufacturerName = other.manufacturerName;
	other.manufacturerName = nullptr;
	currId = other.currId;
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CarPart::CarPart(CarPart&& other) noexcept
{
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CarPart::~CarPart()
{
	free();
}

void CarPart::setCurrID()
{
	id++;
	currId = id;
}

void CarPart::setDescr(const char* descr)
{
	if (this->description == nullptr)
		return;
	delete[] this->description;
	const int len = strlen(descr) + 1;
	this->description = new char[len];
	strcpy_s(this->description, len, descr);
}

void CarPart::setMFName(const char* mFName)
{
	if (this->manufacturerName == nullptr)
		return;
	delete[] this->manufacturerName;
	const int len = strlen(mFName) + 1;
	this->manufacturerName = new char[len];
	strcpy_s(this->manufacturerName, len, mFName);
}

unsigned CarPart::getCurrId() const
{
	return currId;
}

const char* CarPart::getDescr() const
{
	return description;
}

const char* CarPart::getMFName() const
{
	return manufacturerName;
}

CarPart::CarPart(const char* mfName, const char* descr)
{
	setCurrID();
	setDescr(descr);
	setMFName(mfName);
}
