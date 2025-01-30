#ifndef FIREBOOK_H
#define FIREBOOK_H

#include <string>
#include "book.h"


class FireBook : public Book
{
	public:
		FireBook() : Book ("Fire", 5), UseAPower(false) {};
		~FireBook() override = default;

		int SoftAttack(int &enemyLife);
		int HardAttack(int &enemyLife);
		int SuperAttack(int &enemyLife);

	private:
		bool UseAPower { false };
};


#endif