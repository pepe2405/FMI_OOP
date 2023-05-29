#include "Engine.h"

Engine::Engine(const char* mFName, const char* descr, int hp) : CarPart(mFName, descr)
{
	setHp(hp);
}

void Engine::setHp(int newHp)
{
	if (hp < 100)
		throw std::exception("Mahai q taq bangiq!");
	this->hp = newHp;
}

int Engine::getHp() const
{
	return hp;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	return os << engine.getCurrId() << " by " <<
		engine.getMFName() << " - " <<
		engine.getDescr() << " - " <<
		engine.hp << " hp" << std::endl;
}


