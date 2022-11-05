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
//             return get_balance();

        }
        else
        {
            cout << "Sorry this is more than what you can withdraw\n"
                    "Please enter valid amount\n";
            cin >> amount;
        }

    }


}

double BankAccount::deposite(double amount)
{
    set_balance(balance + amount); // need to validate amount
    // receipt();
    // return get_balance();
    return 0;
}

void BankAccount::receipt()
{
    cout << "Thank you.\n";
     cout << "Account ID: " << get_accountID() << '\n';
     cout << "New Balance: " << get_balance() << endl;
}

//SavingBankAccount::SavingBankAccount(double balance) : BankAccount(balance)
//{
    // if (balance >= minimumBalance)
    // {
    //     BankAccount(balance);
    // }
    // else
    // {
    //     cout << "Error: the balance is below the minimum\n";
    // }
//}
