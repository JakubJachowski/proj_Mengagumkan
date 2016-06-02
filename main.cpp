#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <time.h>
#include <unistd.h>

#define _WAIT 500000



using namespace std;

void fight(Enemy &, Player &);

int main(int argc, char const *argv[])
{
	Player champ;
	cout<<"Witaj w tej jakże cudownej grze!\nPodaj imie swojej postaci...\n";
	string x,confirm;
	cin>>x;
	champ.setName(x);
	cout<<endl<<champ.description();
	champ.manageSkillPoints();
	cout<<"\n\nCzas wyruszyc na przygode\n";


	while(champ.getWholeHp()>0)
	{
		srand(time(NULL));
		Enemy mob;

		cout<<"\nO nie! Spotkales na swej drodze przeciwnika!";
		cout<<"\nNazywa sie "<<mob.name()<<" i ma "<<mob.getLvl()<<"lvl\n";
		cout<<"\nOto jego statystyki:\n";
		cout<<mob.description();
		cout<<"Czy chcesz sie z nim zmimerzyc? Twoja szansa na ucieczke to "<<champ.getAgility()*4+50<<"%\n";
		cin>>confirm;
		if(confirm=="tak")
		{
			cout<<"Walka!\n";
			fight(mob, champ);
		}
		else
			if(champ.getAgility()*5+50>=rand()%101)
				cout<<"Udalo Ci sie uciec\n";
			else
			{
				cout<<"Nie udalo sie uciec! Walka!\n";
				fight(mob, champ);
			}

	};
}

void fight(Enemy & x, Player & y)
{

	while(y.getWholeHp()>0 && x.getHp()>0)
	{
		if(y.getCharisma()*4>=rand()%101)
		{
			usleep(_WAIT);
			cout<<"Zadajesz obrazenia krytyczne! "<<y.dealDmg()*2<<endl;
			x.takeDmg(y.dealDmg()*2);
		}
		else
		{
			usleep(_WAIT);
			cout<<"Zadajesz obrazenia="<<y.dealDmg()<<endl;
			x.takeDmg(y.dealDmg());
		}

		if(y.getAgility()*4>rand()%101)
		{
			usleep(_WAIT);
			cout<<"Udalo Ci sie uniknac obrazen!\n";
		}
		else
		{
			usleep(_WAIT);
			cout<<x.name()<<" zadal Ci "<<x.dealDmg()<<"pkt obrazen\n";
			y.takeDmg(x.dealDmg());
		}
	}
	if(y.getWholeHp()>0)
	{
		y.setExp(x.giveExp());
		cout<<"\nGratulacje!!! Wygrales!\n";
		cout<<"Zdobywasz "<<x.giveExp()<<" pkt doswiadczenia\n";
		cout<<"oraz "<<x.giveLoot()<<" pieniedzy\n";
		y.setMoney(y.getMoney()+x.giveLoot());
	}
	else
		cout<<"\n\n\n::::KONIEC GRY::::\nZostales pokonany\n";

	while(y.getExp()>=100+y.getLvl()*20)
	{
		usleep(_WAIT);
		y.lvlUp();
		y.setExp(y.getExp()-80-y.getLvl()*20);
	}	

	if(y.getMoney()>=y.getWeaponLvl()*50+100)
	{
		usleep(_WAIT);
		cout<<"\nUdalo Ci sie uzbierac wystarczajaca ilosc zlota aby ulepszyc bron.\nCzy chcesz to uczynic?\n";
		string decide;
		cin>>decide;
				if(decide=="tak")
				{
					y.setMoney(y.getMoney()-y.getWeaponLvl()*100-100);
					y.upgradeWeapon();
					y.updateDmgOnly();
					cout<<"\nBron zostala ulepszona. +5 dmg\n";
				}
	}

	usleep(_WAIT);
	if(y.getWholeHp()>0)
		{
			y.hpRegen();
			cout<<"\nStan Twojej postaci to:\n";
			cout<<y.description();
		}
}