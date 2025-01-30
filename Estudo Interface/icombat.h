#ifndef ICOMBAT_H
#define ICOMBAT_H

using namespace std;

class ICombat
{
	public:
		virtual ~ICombat() = default;

		virtual int SoftAttack(int &enemyLife) = 0;
		virtual int HardAttack(int &enemyLife) = 0;
		virtual int SuperAttack(int &enemyLife) = 0;
};

#endif