#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <time.h>



using namespace std;

void fight(Enemy, Player);

int main(int argc, char const *argv[])
{
	Player champ;
	cout<<"Witaj w tej jakże cudownej grze!\nPodaj imie swojej postaci...\n";
	string x,fight;
	cin>>x;
	champ.setName(x);
	cout<<champ.description();
	champ.manageSkillPoints();
	cout<<"\n\nCzas wyruszyc na przygode\n";

	while(champ.getWholeHp()>0)
	{
		srand(time(NULL));
		Enemy mob;
		cout<<"\nO nie! Spotkales na swej drodze przeciwnika!";
		cout<<"\nNazywa sie "<<mob.name()<<" i ma "<<mob.getLvl()<<"lvl\n";
		cout<<"Czy chcesz sie z nim zmimerzyc? Twoja szansa na ucieczke to "<<champ.getAgility()*4+50<<"%\n";
		cin>>fight;
		if(fight=="tak")
		{
			cout<<"Walka!\n";
			fight(mob, champ);
		}
		else
			if(champ.getAgility()*4+50>=rand()%101)
				cout<<"Udalo Ci sie uciec\n";
			else
			{
				cout<<"Nie udalo sie uciec! Walka!\n";
				fight(mob, champ)
			}

	}

}

void fight(Enemy x, Player y)
{
	while(y.getWholeHp()>0 && x.getHp()>0)
	{
		if(y.getCharisma()*4>=rand()%101)
		{
			cout<<"Zadajesz obrazenia krytyczne! "<<y.dealDmg()*2<<endl;
			x.takeDmg(y.dealDmg()*2);
		}
		else
		{

			cout<<"Zadajesz obrazenia="<<y.dealDmg()<<endl;
			x.takeDmg(y.dealDmg());
		}

		if(y.getAgility()>rand()%101)
		{

			cout<<"Udalo Ci sie uniknac obrazen!\n";
		}
		else
		{

			cout<<x.name()<<" zadal Ci "<<x.dealDmg()<<"pkt obrazen\n";
			y.takeDmg(x.dealDmg());
		}
	}
	if(y.getWholeHp()>0)
		y.setExp(x.giveExp());
	if(y.getExp()>=100+y.getLvl()*20)
	{
		y.lvlUp();
		y.setExp(y.getExp()%(100+y.getLvl()*20));
	}
}