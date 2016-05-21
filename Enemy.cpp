#include "Enemy.h"
#include <time.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Enemy::Enemy()
{
	srand(time(NULL));
	lvl=rand()%20 +1;
	dmg= 10+lvl+rand()%5-5;
	hp= 20+lvl*10+rand()%100;
	loot=(rand()%11 + 1)*lvl;
	if(lvl<5) _name="Zwykly potwor";
	else
		if(lvl<10) _name="Silny potwor";
		else
			if(lvl<15) _name="Bardzo silny potwor";
			else
				_name="Better Run Bitch";

	experience=lvl*8;

}

void Enemy::takeDmg(int x)
{
	hp-=x;
}