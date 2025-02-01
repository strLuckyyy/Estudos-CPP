#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>

using namespace std;

class User
{
    public:
        User(string _login, string _password) : login(_login), password(_password) {};
        ~User() = default;

        string getLogin() { return login; }
        string getPassword() { return password; }

    private:
        string login;
        string password;
};

class UsersManager
{
    public:
        UsersManager() = default;
        ~UsersManager() = default;

        void addUser(User user);
        void removeUser(string login);
        bool userExists(string login);
        bool loginMatches(string login, string password);
        void showUsers();        
};

#endif