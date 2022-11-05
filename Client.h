#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <iostream>
#include "BankApp.h"


using namespace std;

class BankAccount;
class BankApplication;

class Client
{
private:
    string name;
    string address;
    string phoneNumber;
    BankAccount *account;
    BankApplication *app;

public:
    // ========== constructors ==========
    Client(){};
    Client(string &name, string &address, string &phoneNumber, BankApplication* a);

    Client (string name, string address, int phoneNumber , BankApplication* a);
    void createAccount(char type, double balance);

    void createAccount(int &type, double &balance);
    void updateBalance(double nBalance);


    BankAccount get_account();
    friend ostream &operator<<(ostream &out, Client c);
};
#endif
