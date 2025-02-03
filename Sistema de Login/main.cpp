#include <iostream>
#include <string>
#include <list>

#include "user.cpp"

using namespace std;

UsersManager *users = new UsersManager();

void _app();
void _menu();
void _register();
void _login();

int main()
{
    _menu();    
    
    delete users;
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

    cout << "Welcome to the login system!" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "0. Show Users" << endl;
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
        case 0:
            users->showUsers();
            cin >> waitString;
            _menu();
            break;
        default:
            cout << "Invalid option!" << endl;
            cin >> waitString;
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
        cin >> waitString;

        return _register();
    }

    User user(login, password);
    users->addUser(user);

    _menu();
}


void _login()
{
    string login, password;

    cout << "Login: ";
    cin >> login;

    cout << "Password: ";
    cin >> password;

    if(users->loginMatches(login, password))
    {
        cout << "User logged in successfully!" << endl;
        cin >> waitString;

        _app();
    }

    cout << "Login or password incorrect!" << endl;
    cin >> waitString;
    
    _menu();
}

