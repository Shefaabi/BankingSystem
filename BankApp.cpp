#include "BankApp.h"

void BankApplication::addClient()
{
    double balance;
    int type;
    string name, address, phone;
    Client new_client(name, address, phone, this);
    new_client.createAccount(type, balance);
    clinet.push_back(new_client);
    account.push_back(new_client.get_account());
}
void BankApplication::lists()
{
    for (int i = 0; i < clinet.size(); ++i)
    {
        cout << clinet[i];
    }
    cout << endl;
}
void BankApplication::menu()
{
    cout << "Welcome to FCAI Banking Application\n"
         << "1. Create a New Account\n"
         << "2. List Clients and Accounts\n"
         << "3. Withdraw Money\n"
         << "4. Deposit Money\n";
}
void BankApplication::displayMenu()
{
    forTesting();

    int choice;

    do
    {
        menu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                // create a new account
                addClient();
                break;
            case 2:
                // list clients and accounts
                lists();
                break;
            case 3:
            // // Withdraw Money
                withdrawDepositOperator(3);
                break;
             case 4:
            // // Deposit Money
                 withdrawDepositOperator(4);
                break;
            case 5:
                exit(0);
        }
    } while (choice != 5);
}

void BankApplication::run()
{
    displayMenu();
}

void BankApplication :: forTesting()
{
    char t = '1';
    double bal[3] = {1500,50000,2000};
    string names[3] = {"Ahmed" , "Mohamed" , "Sameh"};
    string add[3] = { "21 haram" , "Giza" , "Dokki"};
    int ph[3] = {0123 , 4567 , 8910};
    Client c1(names[0] , add[0] , ph[0], this);
    c1.createAccount(t , bal[0]);
    Client c2(names[1] , add[1] , ph[1],this);
    c2.createAccount(t , bal[1]);
    Client c3(names[2] , add[2] , ph[2] , this);
    c3.createAccount(t , bal[2]);
    clinet.push_back(c1);
    clinet.push_back(c2);
    clinet.push_back(c3);
    account.push_back(c1.get_account());
    account.push_back(c2.get_account());
    account.push_back(c3.get_account());
}
int BankApplication :: validID(string idd)
{
    for(int i  = 0 ;i < clinet.size(); i++)
    {
        if(clinet[i].get_account().get_accountID() == idd)
        {
            return i+1;
        }
    }
    return 0;
}

void BankApplication :: withdrawDepositOperator(int cas)
{
    string str_ID;
    double amount;
    while(true)
    {
        cout << "Please enter your ID\n";
        cin >> str_ID;

        if(validID(str_ID))
        {
            int i = validID(str_ID) - 1;
            cout << "The Account ID is " << clinet[i].get_account().get_accountID() << '\n';
            if(clinet[i].get_account().get_type() == 1)
            {
                cout <<  "The Account Type is Basic Account\n";
            }
            else
                cout << "The Account Type is Saving Account\n";

            if(cas == 3)
            {
                cout << "Your current balance is: " <<  clinet[i].get_account().get_balance() << '\n' <<
                     "Please enter the amount you want to withdraw\n";
                cin >> amount;
                clinet[i].get_account().withdraw(amount);
                break;
            }
            else if(cas == 4)
            {
                cout << "Your current balance is: " <<  clinet[i].get_account().get_balance() << '\n' <<
                     "Please enter the amount you want to deposit\n";
                cin >> amount;
                clinet[i].get_account().deposit(amount);
                break;
            }
        }
        else
        {
            cout << "Invalid ID!\n" ;
        }

    }

}
void BankApplication :: balanceEditing(double nBalance ,string id)
{
    for(int i  = 0 ;i < clinet.size(); i++)
    {
        if(id == clinet[i].get_account().get_accountID())
        {
            clinet[i].updateBalance(nBalance);
            break;
        }
    }
}

