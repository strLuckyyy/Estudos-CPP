#include <iostream>
#include <string>
#include <fstream>

#include "user.h"

using namespace std;


void UsersManager::addUser(User user)
{
    users.insert(users.end(), user);

    if(users.back().getLogin() != user.getLogin() && users.back().getPassword() != user.getPassword())
    {
        cout << "Error registering user!" << endl;
        return;
    }

    cout << "User registered successfully!" << endl;
}

void UsersManager::removeUser(string login)
{
    for (auto it = users.begin(); it != users.end(); it++)
    {
        if (it->getLogin() == login)
        {
            users.erase(it);
            break;
        }
    }


    cout << "User not found!" << endl;
}

bool UsersManager::userExists(string login)
{
    for (User user : users)
    {
        if (user.getLogin() == login)
        {
            return true;
        }
    }

    return false;
}

bool UsersManager::loginMatches(string login, string password)
{
    for (User user : users)
    {
        if (user.getLogin() == login && user.getPassword() == password)
        {
            return true;
        }
    }

    return false;
}

void UsersManager::showUsers()
{
    for (User user : users)
    {
        cout << "Login: " << user.getLogin() << endl;
        cout << "Password: " << user.getPassword() << endl;
    }
}

void UsersManager::saveUsers()
{
    fstream file("users.txt", ios::out);

    for (User user : users)
    {
        file << user.getLogin() << " " << user.getPassword() << endl;
    }

    file.close();
}

void UsersManager::loadUsers()
{
    fstream file("users.txt", ios::in);

    string login, password;

    while (file >> login >> password)
    {
        User user(login, password);
        users.insert(users.end(), user);
    }

    file.close();
}
