#include "Player.h"

int Player::id = 0;

Player::Player()
{
	points = 0;
	level = Levels::first;
	id++;
	currId = id;
}

bool Player::levelUp()
{
	const Levels lvl = level;
	switch (lvl)
	{
	case Levels::first:
		return points > 256 ? true : false;
	case Levels::second:
		return points > 512 ? true : false;
	case Levels::third:
		return points > 1024 ? true : false;
	case Levels::fourth:
		return points > 2058 ? true : false;
	case Levels::fifth: 
		return false;
	}
	return false;
}

int Player::getCurrId() const
{
	return currId;
}

Levels Player::getLevel() const
{
	return level;
}

int Player::getPoints() const
{
	return points;
}



