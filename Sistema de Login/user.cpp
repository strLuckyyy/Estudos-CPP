#include <iostream>
#include <string>
#include <fstream>

#include "user.h"

using namespace std;

string waitString;


void UsersManager::addUser(User user)
{
    

    if(userExists(user.getLogin()))
    {
        cout << "User already exists!" << endl;
        cin >> waitString;

        return;
    }

    users.insert(users.end(), user);

    if(users.back().getLogin() != user.getLogin() && users.back().getPassword() != user.getPassword())
    {
        cout << "Error registering user!" << endl;
        cin >> waitString;

        return;
    }

    cout << "User registered successfully!" << endl;
    saveUsers();
    cin >> waitString;
}

void UsersManager::removeUser(string login)
{
    for (auto it = users.begin(); it != users.end(); it++)
    {
        if (it->getLogin() == login)
        {
            users.erase(it);
            saveUsers();
            break;
        }
    }

    cout << "User not found!" << endl;
    cin >> waitString;
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
    if (users.empty())
    {
        loadUsers();

        if(users.empty())
        {
            cout << "No users registered!" << endl;
            cin >> waitString;

            return;
        }
    }

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
    loadUsers();
}

void UsersManager::loadUsers()
{
    users.clear();

    fstream file("users.txt", ios::in);

    string login, password;

    while (file >> login >> password)
    {
        User user(login, password);
        users.insert(users.end(), user);
    }

    file.close();
}
