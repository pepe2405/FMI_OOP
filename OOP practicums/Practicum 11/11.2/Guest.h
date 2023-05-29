#pragma once
#include "Player.h"

class Guest : public Player
{
	int _availableTime{};
	void setAvailableTime(int availableTime);

public:
	Guest(int availableTime);
	bool levelUp() override;
};