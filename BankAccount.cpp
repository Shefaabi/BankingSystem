#include "BankAccount.h"

BankAccount::BankAccount(double balance)
{
    this->balance = balance;
    // this->owner = owner;
    set_accountID();
    cout << "An account was created with ID" << accountID
         << " and Starting Balance " << balance << "L.E.";
}

// ========== set & get ==========
void BankAccount::set_accountID()
{
    // id++;
    accountID = "FCAI-";
}

void BankAccount::set_balance(double balance)
{
    this->balance = balance;
}

// void set_client()

// ========== operations ==========
double BankAccount::withdraw(double amount)
{
    string str_ID;
    cout << "Please enter your ID\n";
    cin >> str_ID;

    bool is_valid = 0;
    // need a loop
    while (is_valid)
    {
        if (amount <= balance)
        {
            set_balance(balance - amount);
            is_valid = true;
            // receipt();
            // return get_balance();
        }

        else
        {
            cout << "Sorry. This is more than what you can withdraw.\n";
        }
    }
}

double BankAccount::deposite(double amount)
{
    set_balance(balance + amount); // need to validate amount
                                   // receipt();
    // return get_balance();
}

void BankAccount::receipt()
{
    cout << "Thank you.\n";
    // cout << "Account ID: " << get_accountID();
    cout << "New Balance: " << get_balance() << endl;
}

SavingBankAccount::SavingBankAccount(double balance) : BankAccount(balance)
{
    // if (balance >= minimumBalance)
    // {
    //     BankAccount(balance);
    // }
    // else
    // {
    //     cout << "Error: the balance is below the minimum\n";
    // }
}
