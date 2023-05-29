#include "StudentTicket.h"
#include <cstring>
StudentTicket::StudentTicket(const char* name, double price)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->price = price / 2;
}
