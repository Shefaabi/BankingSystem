#include "BankApp.h"

void BankApplication::addClient()
{
    double balance;
    int type;
    string name, address, phone;
    Client new_client(name, address, phone);
    new_client.createAccount(type, balance);
    clinet.push_back(new_client);
    account.push_back(new_client.get_account());
}

void BankApplication::lists()
{
    for (int i = 0; i < 2; ++i)
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
        // case 3:
        // // Withdraw Money
        
        // case 4:
        // // Deposit Money
        case 5:
            exit(0);
        }
    } while (choice != 5);
}

void BankApplication::run()
{
    displayMenu();
}
