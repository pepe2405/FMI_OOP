#pragma once
#include <ostream>

class CarPart
{
	static unsigned id;
	unsigned currId = 0;
	char* manufacturerName = nullptr;
	char* description = nullptr;

	void setCurrID();
	void setMFName(const char* mFName);
	void setDescr(const char* descr);

	void free();
	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other);

public:
	CarPart() = default;
	CarPart(const char* mfName, const char* descr);

	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);

	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;

	unsigned getCurrId() const;
	const char* getMFName() const;
	const char* getDescr() const;

	~CarPart();
};
