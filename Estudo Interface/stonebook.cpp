#include <iostream>
#include <string>
#include "stonebook.h"

using namespace std;


int StoneBook::SoftAttack(int &enemyLife)
{
	cout<<"Stone Throw!"<<endl;

	return Book::DealDamage(1, enemyLife);
}

int StoneBook::HardAttack(int &enemyLife)
{
	cout<<"Stone Pilar!"<<endl;

	return Book::DealDamage(1.5f, enemyLife);
}

int StoneBook::SuperAttack(int &enemyLife)
{
	cout<<"Stone Storm"<<endl;

	return Book::DealDamage(2, enemyLife);
}
