#ifndef USER_H
#define USER_H

#include <string>

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

#endif