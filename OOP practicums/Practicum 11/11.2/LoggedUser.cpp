#include "LoggedUser.h"

#include <cstring>
#include <exception>
#include <iostream>

void LoggedUser::setPassword(const char* password)
{
	const int len = strlen(password) + 1;
	if (len > 9)
		throw std::exception("Password too long!");
	strcpy_s(_password, len, password);
}

LoggedUser::LoggedUser(const char* password)
{
	setPassword(password);
	isLogged = false;
}

bool LoggedUser::levelUp()
{
	if (!isLogged)
	{
		std::cout << "User not logged in!" << std::endl;
		return false;
	}
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

void LoggedUser::login(int id, const char* password)
{
	if (strcmp(_password, password) == 0 && getCurrId() == id)
	{
		isLogged = true;
		std::cout << "Logged in successfuly!" << std::endl;
	}
	else
		std::cout << "Wrong id or password!" << std::endl;
}


