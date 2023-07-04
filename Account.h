#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "types.h"

using namespace std;

const string USER_DIR = "USER/";

class Account
{
public:
    Account(const string& filename);
    ~Account();

    bool registerUser(const char* username, const char* password);
    int login(const char* username, const char* password, User* user);
    bool changePassword(const char* username, const char* password);

private:
    string filename;

};

#endif
