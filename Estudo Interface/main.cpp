#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <cassert>
#include <stdlib.h>

#include "firebook.cpp"
#include "waterbook.cpp"
#include "stonebook.cpp"

using namespace std;


int enemyLife = 500;
Book* books[3] = {new FireBook(), new WaterBook(), new StoneBook()};
Book* currentBook = books[0];

bool contains(string& v, char t);
void bookMenu();
void bookManagement();


int main() {
    while (enemyLife > 0) {
		system("reset");
        cout << "ON BATTLE - enemy life: " << enemyLife << endl;
        cout << "1. Attack." << endl;
        cout << "2. Change Book" << endl;
        cout << "3. Run." << endl;

        string answer;
        getline(cin, answer);

        if (contains(answer, '1')) {
            bookMenu();
            if (enemyLife <= 0) {
                cout << "YOU WIN!" << endl;
                break;
            }
        } else if (contains(answer, '2')) {
            bookManagement();
        } else if (contains(answer, '3')) {
            cout << "You ran away... Coward!" << endl;
            break;
        } else {
            cout << "Invalid option." << endl;
        }
    }

    // Cleanup
    for (auto& book : books) {
        delete book;
    }

    return 0;
}

bool contains(string& v, char t)
{
    bool found = (find(v.begin(), v.end(), t) != v.end());
    return found;
}

void bookManagement()
{
	system("reset");
	cout<<"Which book do you wish for?"<<endl;
	cout<<""<<endl;
	cout<<"1. FireBook"<<endl;
	cout<<"2. WaterBook"<<endl;
	cout<<"3. StoneBook"<<endl;
	cout<<"4. Back"<<endl;

	string answer;
	getline(cin, answer);

	if (contains(answer, '1'))
	{
		currentBook = books[0];
	}
	else if (contains(answer, '2'))
	{
		currentBook = books[1];
	}
	else if (contains(answer, '3'))
	{
		currentBook = books[2];
	}
	else if (contains(answer, '4'))
	{
		return;
	}
	else
	{
		cout<<"This is not a answer"<<endl;
		bookManagement();
	}
}

void bookMenu()
{
	system("reset");
	currentBook->showBookName();

	cout<<"What do you wanna do?"<<endl;

	cout<<"1. Soft Attack."<<endl;
	cout<<"2. Hard Attack."<<endl;
	cout<<"3. Super Attack."<<endl;
	cout<<"4. Back to Menu."<<endl;

	string answer;
	getline(cin, answer);

	if (contains(answer, '1'))
	{
		enemyLife = currentBook->SoftAttack(enemyLife);
	}
	else if (contains(answer, '2'))
	{
		enemyLife = currentBook->HardAttack(enemyLife);
	}
	else if (contains(answer, '3'))
	{
		enemyLife = currentBook->SuperAttack(enemyLife);
	}
	else if (contains(answer, '4'))
	{
		return;
	}
	else
	{
		cout<<"This is not a answer."<<endl;
		bookMenu();
	}
}
