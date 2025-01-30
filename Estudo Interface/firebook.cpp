#include <iostream>
#include <string>
#include "firebook.h"

using namespace std;


int FireBook::SoftAttack(int &enemyLife)
{
	cout<<"Fire Balls"<<endl;
	UseAPower = true;

	return Book::DealDamage(1, enemyLife);
}

int FireBook::HardAttack(int &enemyLife)
{
	cout<<"Fire Walls"<<endl;
	UseAPower = true;

	return Book::DealDamage(2, enemyLife);
}

int FireBook::SuperAttack(int &enemyLife)
{
	if (!UseAPower)
	{
		cout<<"Nothing happens"<<endl;
		cin.get();

		return enemyLife;
	}
	
	cout<<"You teletransportated to fire"<<endl;
	UseAPower = false;
	cin.get();

	return enemyLife;
}
