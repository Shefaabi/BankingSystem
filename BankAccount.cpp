#include "BankAccount.h"

int BankAccount :: id = 0;

BankAccount::BankAccount(double balance, BankApplication* a , int type )
{
    this->balance = balance;
//    this->owner = &owner;
    this->app = a;
    this->type = type;
    set_accountID();
    cout << "An account was created with ID: " << accountID
         << " and Starting Balance " << balance << "L.E.\n";
}

// ========== set & get ==========
void BankAccount :: set_accountID()
{
    id++;
    int dif;
    string temp;
    dif = 3 - to_string(id).size();
    for(int i = 0; i < dif ; i++)
    {
         temp += '0';
    }
    temp += to_string(id);

    accountID = "FCAI-" + temp;
}

void BankAccount::set_balance(double balance)
{
    this->balance = balance;
}

// void set_client()

// ========== operations ==========
double BankAccount::withdraw(double amount)
{
    bool is_valid = false;
    double newBalance = balance - amount;



    while (!is_valid)
    {
        if (amount <= balance)
        {
            set_balance(balance - amount);
            is_valid = true;
             receipt();
             app->balanceEditing(newBalance,accountID);
             return get_balance();

        }
        else
        {
            cout << "Sorry this is more than what you can withdraw\n"
                    "Please enter valid amount\n";
            cin >> amount;
        }

    }

    return get_balance();
}

double BankAccount :: deposit(double amount)
{
    set_balance(balance + amount); // need to validate amount
    app->balanceEditing(balance, accountID);
     receipt();
     return get_balance();
}

void BankAccount::receipt()
{
    cout << "Thank you.\n";
     cout << "Account ID: " << get_accountID() << '\n';
     cout << "New Balance: " << get_balance() << endl;
}

SavingBankAccount::SavingBankAccount(double balance, int type)
{
    this->minimumBalance = 1000;

    if (balance >= minimumBalance)
    {
        set_balance(balance);
        set_accountID();
        cout << "An account was created with ID: " << accountID
             << " and Starting Balance " << balance << "L.E.\n";
    }

    else
    {
        cout << "\nError: The balance is below the minimum balance.\n";
    }
}

double SavingBankAccount::withdraw(double amount)
{
    while (true)
    {
        if ((balance - amount) >= minimumBalance)
        {
            BankAccount::withdraw(amount);
            break;
        }
        else
        {
            cout << "Sorry the amount is more than what you can withdraw.\n";
            cout << "Please enter a valid amount:\n";
            cin >> amount;
        }
    }
}
