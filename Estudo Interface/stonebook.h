#ifndef STONEBOOK_H
#define STONEBOOK_H

#include <string>
#include "book.h"

class StoneBook : public Book
{
	public:
		StoneBook() : Book("Stone", 8) {}
		~StoneBook() override = default;
		
		int SoftAttack(int &enemyLife);
		int HardAttack(int &enemyLife);
		int SuperAttack(int &enemyLife);
};

#endif