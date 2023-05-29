#include "GroupTicket.h"

GroupTicket::GroupTicket(const char* name, double price)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->price = price * 0.8;
}
