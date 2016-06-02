#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
	_name="moron";
	baseHp=200;
	_hp=0;
	experience=0;
	lvl=1;
	strenght=0;
	vitality=0;
	agility=0;
	charisma=0;
	baseDmg=10;
	wholeDmg=10;
	wholeHp=100;
	skillPoints=10;
	money=0;
	weaponLvl=0;
}

string Player::description()
{
	return _name + " lv " + to_string(lvl) +
			"\nexp: " + to_string(experience) + 
			"\nStatystyki:\n" + "Str=" + to_string(strenght) +
			"\nVit=" + to_string(vitality) +
			"\nAgl=" + to_string(agility) + 
			"\nChr=" + to_string(charisma) +
			"\nHP=" + to_string(wholeHp) +
			"\nDMG=" + to_string(wholeDmg) +
			"\n";
}


void Player::setName(string nameAux)
{
	_name=nameAux;
};

void Player::update()
{
	wholeDmg=2*strenght + baseDmg + weaponLvl*5;
	wholeHp=20*vitality + baseHp;
}

void Player::manageSkillPoints()
{
	cout<<"Masz do rozdania "<<getSkillPoints()<<" punktow umiejetnosci\n";
	cout<<"1-sila, 2-zrecznosc, 3-charyzma, 4- witalnosc\n";

	for(int i=0;i<getSkillPoints();)
	{
		int aux;
		cin>>aux;
		switch(aux)
		{
			case 1: buffStrenght(); i++; break;
			case 2: buffAgility(); i++; break;
			case 3: buffCharisma(); i++; break;
			case 4: buffVitality(); i++; break;
			default: cout<<"podales zla liczbe\n"; break;
		}
	}
	update();
	cout<<"\nWszystkie punkty rozdane\n";
}

void Player::takeDmg(int x)
{
	wholeHp-=x;
}

void Player::setExp(int x)
{
	experience=x;
}

void Player::lvlUp()
{
	cout<<"\n\nGratulacje!!! Udalo Ci sie osiagnac nastepny poziom\n";
	skillPoints=4;
	manageSkillPoints();
	lvl++;
	update();
}

void Player::setMoney(int x)
{
	money=x;
}
void Player::hpRegen()
{
	wholeHp=wholeHp+(baseHp+20*vitality)*(10+vitality)/40;
	cout<<"Zregenerowales "<<(baseHp+20*vitality)*vitality/40<<" HP\n";
	if(wholeHp>baseHp+20*vitality)
		wholeHp=baseHp+20*vitality;
}

void Player::updateDmgOnly()
{
	wholeDmg=2*strenght + baseDmg + weaponLvl*5;
}