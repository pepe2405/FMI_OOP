#pragma once
#include "Player.h"

class PremiumUser : public Player
{
	char* _username = nullptr;
	void setUsername(const char* username);

	void free();
	void copyFrom(const PremiumUser& other);
	void moveFrom(PremiumUser&& other);

public:
	PremiumUser(const char* username);

	PremiumUser(const PremiumUser& other);
	PremiumUser& operator=(const PremiumUser& other);

	PremiumUser(PremiumUser&& other) noexcept;
	PremiumUser& operator=(PremiumUser&& other) noexcept;

	~PremiumUser() override;

	bool levelUp() override;
};