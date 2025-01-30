#ifndef WATERBOOK_H
#define WATERBOOK_H

#include <string>
#include "book.h"


class WaterBook : public Book
{
	public:
		WaterBook()  : Book("Water", 6), canFlood(true), levelFlood(1) { }
		~WaterBook() override = default;

		int SoftAttack(int &enemyLife);
		int HardAttack(int &enemyLife);
		int SuperAttack(int &enemyLife);

	private:
		bool canFlood { true };
		int levelFlood { 1 };
};

#endif