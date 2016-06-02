#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Enemy
{
	string _name;
	int lvl;
	int dmg;
	int hp;
	int loot;
	int experience;

public:
	Enemy();
	int dealDmg() {return dmg; };
	void takeDmg(int);
	int giveLoot() {return loot; };
	string name() {return _name; };
	int getLvl() {return lvl; };
	int getHp() {return hp; };
	int giveExp() {return experience; }

	string description();

};