#include "PremiumUser.h"

#include <algorithm>
#include <cstring>

void PremiumUser::free()
{
	delete[] _username;
	points = 0;
}

void PremiumUser::copyFrom(const PremiumUser& other)
{
	const int len = strlen(other._username) + 1;
	_username = new char[len];
	strcpy_s(_username, len, other._username);
}

void PremiumUser::moveFrom(PremiumUser&& other)
{
	_username = other._username;
	other._username = nullptr;
}

PremiumUser::PremiumUser(const PremiumUser& other) : Player(other)
{
	copyFrom(other);
}

PremiumUser& PremiumUser::operator=(const PremiumUser& other)
{
	if (this != &other)
	{
		Player::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

PremiumUser::PremiumUser(PremiumUser&& other) noexcept
{
	moveFrom(std::move(other));
}

PremiumUser& PremiumUser::operator=(PremiumUser&& other) noexcept
{
	if (this != &other)
	{
		Player::operator=(other);
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void PremiumUser::setUsername(const char* username)
{
	if (username == nullptr)
		return;
	delete[] _username;
	const int len = strlen(username) + 1;
	_username = new char[len];
	strcpy_s(_username, len, username);
}

PremiumUser::PremiumUser(const char* username)
{
	setUsername(username);
}

bool PremiumUser::levelUp()
{
	if (points > 256 && level != Levels::fifth)
		return true;
	return false;
}

PremiumUser::~PremiumUser()
{
	free();
}
