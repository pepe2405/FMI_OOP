#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket
{
public:
	GroupTicket() = default;
	GroupTicket(const char* name, double price);
};