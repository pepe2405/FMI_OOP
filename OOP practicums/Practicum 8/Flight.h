#pragma once

class Flight
{
	static unsigned createdFlights;
	int id;
	char origin[64]{};
	char dest[64]{};
	double price;
	unsigned takeOffHour{};
	bool reserved = false;

	void setOrigin(const char* newOrigin);
	void setDest(const char* newDest);

	bool isValidString(const char* str) const;
public:
	Flight();
	Flight(const char* origin, const char* dest, double price, int takeOffHour);
	void setTOHour(unsigned newHour);
	int getId() const;
	int getTakeOfHour() const;
	const char* getOrigin() const;
	const char* getDest() const;
	double getPrice() const;
	bool isReserved() const;
	void reserve();
};