#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <iostream>
#include "BankApp.h"

using namespace std;

class BankAccount;
class BankApplication;
class SavingBankAccount;

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
    Client(string name, string address, int phoneNumber);

    void createAccount(char type, double balance);
    void createAccount(int &type, double &balance);

    BankAccount &get_account();

    friend ostream &operator<<(ostream &out, Client c);
    // ~Client() { delete account; }
};
#endif
