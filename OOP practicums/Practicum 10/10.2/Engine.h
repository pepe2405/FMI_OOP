#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
	int hp = 0;
	void setHp(int newHp);

public:
	Engine() = default;
	Engine(const char* mFName, const char* descr, int hp);
	friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
	int getHp() const;
};
