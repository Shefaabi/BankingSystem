#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <iostream>
#include "BankAccount.h"

using namespace std;

class Client
{
private:
    string name;
    string address;
    string phoneNumber;
    BankAccount *account;

public:
    // ========== constructors ==========
    Client(){};
    Client(string &name, string &address, string &phoneNumber);

    void createAccount(int &type, double &balance);

    BankAccount get_account();
    friend ostream &operator<<(ostream &out, Client c);
};
#endif