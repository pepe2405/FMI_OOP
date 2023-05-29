#pragma once
#include "CarPart.h"

class Tire : public CarPart
{
	int width = 0;
	int profile = 0;
	int rimSize = 0;
	void setWidth(int newWidth);
	void setProfile(int newProfile);
	void setRimSize(int newRimSize);

public:
	Tire() = default;
	Tire(const char* mFName, const char* descr, int width, int profile, int rimSize);
	friend std::ostream& operator<<(std::ostream& os, const Tire& tire);
	int getWidth() const;
	int getProfile() const;
	int getRimSize() const;
};

