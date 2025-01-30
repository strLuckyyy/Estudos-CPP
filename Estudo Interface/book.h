#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "icombat.h"

using namespace std;

class Book : public ICombat
{
	public:
		Book(const string element_, double damage_) : element(element_), damage(damage_) {};
		virtual ~Book() = default;

		void showBookName()
		{
			cout<<"Now, I'm using a "<<element<<"!"<<endl;
		};

		int DealDamage(const int multiplier, int &enemyLife)
		{
			int totalDamage = static_cast<int>(damage * multiplier);
			cout << "Deal " << totalDamage << " of damage!" << endl;
			cin.get();

			return enemyLife - totalDamage;
		};

		int SoftAttack(int &enemyLife) override { return 0; };
		int HardAttack(int &enemyLife) override { return 0; };
		int SuperAttack(int &enemyLife) override { return 0; };

	protected:
		string element { "empty" };
		float damage { 0.0f };
};

#endif