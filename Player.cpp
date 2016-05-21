#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
	_name="moron";
	baseHp=100;
	_hp=0;
	experience=0;
	lvl=1;
	strenght=0;
	vitality=0;
	agility=0;
	charisma=0;
	baseDmg=10;
	weaponDmg=0;
	wholeDmg=10;
	wholeHp=100;
	skillPoints=10;
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
	wholeDmg=2*strenght + baseDmg + weaponDmg;
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
	cout<<"\nGratulacje! Wszystkie punkty rozdane, oto Twoja postac:\n";
	cout<<description();
}

void Player::takeDmg(int x)
{
	wholeHp-=x;
}

void Player::setExp(int x)
{
	experience+=x;
}

void Player::lvlUp()
{
	cout<<"\n\nGratulacje!!! Udalo Ci sie osiagnac nastepny poziom\n";
	skillPoints+=4;
	manageSkillPoints();
}