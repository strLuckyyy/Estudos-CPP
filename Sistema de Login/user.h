#ifndef USER_H
#define USER_H

#include <string>
#include <list>

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

        void loadUsers();
        void addUser(User user);
        void removeUser(string login);
        bool loginMatches(string login, string password);
        void showUsers();
    
    private:
        list<User> users;

        bool userExists(string login);
        void saveUsers();
};

#endif