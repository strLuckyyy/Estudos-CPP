#include <iostream>
#include <string>
#include <list>

#include "user.h"

using namespace std;

list<User> users;

void _app();
void _menu();
void _register();
void _login();

int main()
{
    _menu();
    return 0;
}


void _app()
{
    cout << "Welcome to the app! \nHere there's nothing!" << endl;
    cout << "Press any key to logout..." << endl;
    cin.get();

    _menu();
}

void _menu()
{
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
    int option;
    cin >> option;

    switch (option)
    {
        case 1:
            _login();
            break;
        case 2:
            _register();
            break;
        case 3:
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
}


void _register()
{
    string login, password, confirm_password;

    cout << "Login: ";
    cin >> login;

    cout << "Password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirm_password;

    if (password != confirm_password)
    {
        cout << "Passwords don't match!" << endl;
        return _register();
    }


    User user(login, password);
    users.insert(users.end(), user);


    if (users.back().getLogin() != login && users.back().getPassword() != password)
    {
        cout << "Error registering user!" << endl;
        return _register();   
    }

    cout << "User registered successfully!" << endl;
    _menu();
}


void _login()
{
    string login, password;

    cout << "Login: ";
    cin >> login;

    cout << "Password: ";
    cin >> password;

    for (User user : users)
    {
        if(user.getLogin() == login && user.getPassword() == password)
        {
            cout << "User logged in successfully!" << endl;
            _app();
        }
    }

    cout << "Login or password incorrect!" << endl;
    _login();
}

