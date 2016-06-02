#include "Enemy.h"
#include <time.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Enemy::Enemy()
{
	srand(time(NULL));
	lvl=rand()%30 +1;
	dmg= 10+lvl+rand()%5-5;
	hp= 20+lvl*10+rand()%100;
	loot=(rand()%11 + 1)*lvl;
	if(lvl<5) _name="Zgnily zdechlak";
	else
		if(lvl<10) _name="Przypakowany leszcz";
		else
			if(lvl<15) _name="Koksik z pobliskiej silowni";
			else
				if(lvl<20)
				_name="Kickboxer z pato osiedla";
				else
					if(lvl<25)
						_name="Psychopata z tulipanem";
					else
						_name="Schizofrenik ex-komandos z AK-47";

	experience=lvl*10+20;

}

void Enemy::takeDmg(int x)
{
	hp-=x;
}

string Enemy::description()
{
	return _name + "\nDMG=" + to_string(dmg) + "\nHP=" + to_string(hp) + "\n";
}
