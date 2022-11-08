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
    static int id ;
    int type;
    BankApplication *app;
    Client *owner;

public:
    // ========== constructors ==========
    BankAccount() { balance = 0.0; }

    BankAccount(double balance , BankApplication * a , int type);
    void set_accountID();
    void set_balance(double balance);
    string get_accountID() { return accountID; }
    double get_balance() { return balance; }
    int get_type(){ return type; }
    double withdraw(double amount);
    double deposit(double amount);
    void receipt();
    // BankAccount(double balance, Client *owner)
    // {
    //     this->balance = balance;
    //     this->owner = owner;
    //     set_accountID();
    //     cout << "An account was created with ID" << accountID
    //          << " and Starting Balance " << balance << "L.E.";
    // }

    // // ========== set & get ==========


//     void set_balance(double balance)
//     {
//         this->balance = balance;
//     }

    // // void set_client()

    // string get_accountID() { return accountID; }
    // double get_balance() { return balance; }

    // // ========== operations ==========
    // int withdraw(double amount)
    // {
    //     // need a loop
    //     if (amount <= balance)
    //     {
    //         set_balance(balance - amount);
    //         // receipt();
    //         return get_balance();
    //     }

    //     else
    //     {
    //         cout << "Sorry. This is more than what you can withdraw.\n";
    //     }
    // }

    // int deposite(double amount)
    // {
    //     set_balance(balance + amount); // need to validate amount
    //                                    // receipt();
    //     return get_balance();
    // }

    // void receipt()
    // {
    //     cout << "Thank you.\n";
    //     cout << "Account ID: " << get_accountID();
    //     cout << "New Balance: " << get_balance() << endl;
    // }
};

class SavingBankAccount : public BankAccount
{
private:
    double minimumBalance;

public:
    // ========== constructors ==========
    SavingBankAccount(double balance);

    // ========== set & get ==========

    // ========== operations ==========
};
#endif
