#include "BankAccount.h"

int BankAccount ::id = 0;

BankAccount::BankAccount(double balance, int type)
{
    this->balance = balance;
    this->type = type;

    set_accountID();
    cout << "An account was created with ID: " << accountID
         << " and Starting Balance " << balance << "L.E.\n";
}

// ========== set & get ==========
void BankAccount ::set_accountID()
{
    id++;
    int dif;
    string temp;
    dif = 3 - to_string(id).size();
    for (int i = 0; i < dif; i++)
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

double BankAccount ::deposit(double amount)
{
    set_balance(balance + amount);
    receipt();
    return get_balance();
}

void BankAccount::receipt()
{
    cout << "-------------------\n";
    cout << "Thank you.\n";
    cout << "Account ID: " << get_accountID() << '\n';
    cout << "New Balance: " << get_balance() << endl;
    cout << "-------------------\n";
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

double SavingBankAccount ::deposit(double amount)
{
    int select;
    while (true)
    {
        if (amount >= 100)
        {
            set_balance(balance + amount);
            receipt();
            break;
        }

        else
        {
            cout << "Sorry, you have to deposit 100 L.E. or more\n";
            cout << "Enter (1) to change the amount\nEnter (2) to exit\n";
            cin >> select;

            if (select == 1)
            {
                cout << "Enter the amount that you want to deposit\n";
                cin >> amount;
            }
            else if (select == 2)
            {
                break;
            }
        }
    }

    return get_balance();
}
