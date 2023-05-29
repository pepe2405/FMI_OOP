#include "Guest.h"
#include "Player.h"
#include "LoggedUser.h"

int main()
{
	Guest g(23);
	Player p;
	Player p1;
	Guest g1(20);
	LoggedUser lu("123");
	lu.levelUp();
	lu.login(5, "123");
	
}