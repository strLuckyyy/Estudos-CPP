#include <iostream>
#include <string>
#include <list>

#include "user.h"

using namespace std;

list<User> users; // this will be deleted
string waitString;

void _app();
void _menu();
void _register();
void _login();

int main()
{
    _menu();    
    
    //cleanup
    for(auto& user : users)
    {
        delete &user;
    }

    return 0;
}


void _app()
{
    system("reset");
    cout << "Welcome to the app! \nThere's nothing here!" << endl;
    cout << "Press any key to logout..." << endl;
    cin >> waitString;

    _menu();
}

void _menu()
{
    system("reset");
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
            return;
        default:
            cout << "Invalid option!" << endl;
            _menu();
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
        cin >> waitString;

        return _register();   
    }

    cout << "User registered successfully!" << endl;
    cin >> waitString;

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
            cin >> waitString;

            _app();
        }
    }

    cout << "Login or password incorrect!" << endl;
    cin >> waitString;
    
    _menu();
}

