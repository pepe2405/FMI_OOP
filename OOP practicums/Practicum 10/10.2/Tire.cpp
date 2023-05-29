#include "Tire.h"

void Tire::setProfile(int newProfile)
{
	if (newProfile < 30 || newProfile > 80)
		throw std::exception("Invalid profile!");
	this->profile = newProfile;
}

void Tire::setRimSize(int newRimSize)
{
	if (newRimSize < 13 || newRimSize > 21)
		throw std::exception("Invalid rim size!");
	this->rimSize = newRimSize;
}

void Tire::setWidth(int newWidth)
{
	if (newWidth < 155 || newWidth > 365)
		throw std::exception("Invalid width!");
	this->width = newWidth;
}

Tire::Tire(const char* mFName, const char* descr, int width, int profile, int rimSize) : CarPart(mFName, descr)
{
	setWidth(width);
	setProfile(profile);
	setRimSize(rimSize);
}

int Tire::getWidth() const
{
	return width;
}

int Tire::getProfile() const
{
	return profile;
}

int Tire::getRimSize() const
{
	return rimSize;
}

std::ostream& operator<<(std::ostream& os, const Tire& tire)
{
	return os << tire.getCurrId() << " by " << 
		         tire.getMFName() << " - " <<
				 tire.getDescr() << " - " <<
		         tire.getWidth() << '/' << tire.getProfile() << 'R' << tire.getRimSize() << std::endl;
}
