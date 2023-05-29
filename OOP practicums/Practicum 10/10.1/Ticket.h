#pragma once

class Ticket
{
	void free();
	void copyFrom(const Ticket& other);
	void moveFrom(Ticket&& other);

protected:
	char* name = nullptr;
	double price = 0;

public:
	Ticket() = default;
	Ticket(const char* name, unsigned price);

	Ticket(const Ticket& other);
	Ticket& operator=(const Ticket& other);

	Ticket(Ticket&& other) noexcept;
	Ticket& operator=(Ticket&& other) noexcept;

	void print() const;
	~Ticket();
};