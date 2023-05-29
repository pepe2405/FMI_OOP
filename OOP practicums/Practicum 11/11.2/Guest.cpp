#include "Guest.h"

#include <exception>

Guest::Guest(int availableTime)
{
	setAvailableTime(availableTime);
}

void Guest::setAvailableTime(int availableTime)
{
	if (availableTime < 0)
		throw std::exception("Can't play negative time!");
	_availableTime = availableTime;
}

bool Guest::levelUp()
{
	return false;
}
