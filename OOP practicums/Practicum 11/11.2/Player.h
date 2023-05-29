#pragma once

enum class Levels
{
	first,
	second,
	third,
	fourth,
	fifth
};

class Player
{
	static int id;
	int currId;

protected:
	int points;
	Levels level;

public:
	Player();

	virtual bool levelUp();
	int getCurrId() const;
	int getPoints() const;
	Levels getLevel() const;

	virtual ~Player() = default;
};