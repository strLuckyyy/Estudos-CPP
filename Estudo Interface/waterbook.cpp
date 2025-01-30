#include <iostream>
#include <string>
#include "waterbook.h"

using namespace std;


int WaterBook::SoftAttack(int &enemyLife)
{
	cout<<"Water Whip!"<<endl;
	if (!canFlood) { levelFlood++; }

	return Book::DealDamage(levelFlood, enemyLife);
}

int WaterBook::HardAttack(int &enemyLife)
{
	cout<<"Wave"<<endl;
	if (!canFlood) { levelFlood++; }
	
	return Book::DealDamage(static_cast<int>(levelFlood * 1.5f), enemyLife);
}

int WaterBook::SuperAttack(int &enemyLife)
{
	if (canFlood)
	{
		cout<<"Flood!"<<endl;
		canFlood = false;
		cin.get();

		return enemyLife;
	}

	cout<<"The Flood is on "<<levelFlood<<" level."<<endl;
	cin.get();
	
	return enemyLife;
}
