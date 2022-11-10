#include "Client.h"
#include "BankAccount.h"

Client::Client(string &name, string &address, string &phoneNumber)
{
    cout << "Please Enter Client Name\n";
    getline(cin, name);
    this->name = name;
    cout << "Please Enter Client Address\n";
    getline(cin, address);
    this->address = address;
    cout << "Please Enter Client Phone\n";
    cin >> phoneNumber;
    this->phoneNumber = phoneNumber;
}
Client ::Client(string name, string address, int phoneNumber)
{
    this->name = name;
    this->address = address;
    this->phoneNumber = to_string(phoneNumber);
}
void Client::createAccount(char type, double balance)
{
    int t = type - '0';

    if (type == '1')
    {
        this->account = new BankAccount(balance, t);
    }
    else if (type == '2')
    {
        this->account = new SavingBankAccount(balance, t);
    }
}

void Client::createAccount(int &type, double &balance)
{
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving ; Type 1 or 2\n";
    cin >> type;
    cout << "Please Enter the Starting Balance\n";
    cin >> balance;
    if (type == 1)
        this->account = new BankAccount(balance, type);
    else if (type == 2)
        this->account = new SavingBankAccount(balance, type);
}

BankAccount &Client::get_account() { return *(this->account); }

ostream &operator<<(ostream &out, Client c)
{
    out << "Client name: " << c.name;
    out << endl;
    out << "Address: " << c.address;
    out << endl;
    out << "Phone number: " << c.phoneNumber;
    out << endl;
    out << "balance: " << c.get_account().get_balance() << endl;
    return out;
}
