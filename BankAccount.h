#ifndef HEADER_FILE_NAME2
#define HEADER_FILE_NAME2

#include <string>
#include <iostream>
#include "BankApp.h"

using namespace std;

class BankApplication;
class Client;

class BankAccount
{

protected:
    string accountID;
    double balance;
    static int id;
    int type;

public:
    // ========== constructors ==========
    BankAccount() { balance = 0.0; }

    BankAccount(double balance, int type);
    void set_accountID();
    void set_balance(double balance);
    string get_accountID() { return accountID; }
    double get_balance() { return balance; }
    int get_type() { return type; }
    virtual double withdraw(double amount);
    virtual double deposit(double amount);
    void receipt();
};

class SavingBankAccount : public BankAccount
{
private:
    double minimumBalance;

public:
    // ========== constructors ==========
    SavingBankAccount(double balance, int type);
    double withdraw(double amount);
    double deposit(double amount);
};
#endif
