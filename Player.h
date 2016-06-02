#pragma once

#include <stdio.h>
#include <string>



using namespace std;

class Player
{
	string _name;
	int _hp, baseHp, wholeHp;
	int experience;
	int lvl;
	int strenght, vitality, agility, charisma;;
	int baseDmg;
	int wholeDmg;
	int skillPoints;
	int money;
	int weaponLvl;

public:
	Player();

	void buffStrenght() {strenght++;}
	void buffAgility() {agility++;}
	void buffVitality() {vitality++;}
	void buffCharisma() {charisma++;}
	int hp() { return _hp; }
	string name() { return _name; };
	void regen();
	int dealDmg() {return wholeDmg; };
	void takeDmg(int);
	void setName(string);
	void update();
	void lvlUp();
	void manageSkillPoints();
	int getSkillPoints() { return skillPoints; };
	int getWholeHp() {return wholeHp; };
	int getAgility() {return agility; };
	int getCharisma() {return charisma; };
	void setExp(int);
	int getExp() {return experience; };
	int getLvl() {return lvl; };
	void setMoney(int);
	int getMoney() {return money; };
	int getWeaponLvl() {return weaponLvl;};
	void upgradeWeapon() {weaponLvl++;};
	void hpRegen();
	void updateDmgOnly();

	string description();

};
