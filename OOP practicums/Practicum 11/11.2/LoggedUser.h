#pragma once
#include "Player.h"

class LoggedUser : public Player
{
	char _password[8]{};
	bool isLogged = false;
	void setPassword(const char* password);

public:
	LoggedUser(const char* password);
	void login(int id, const char* password);
	bool levelUp() override;
};