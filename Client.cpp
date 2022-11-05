#include "Client.h"
#include "BankAccount.h"


Client::Client(string &name, string &address, string &phoneNumber, BankApplication* a)
{
    cout << "Please Enter Client Name\n";
    getline(cin, name);
    this->name = name;
    cout << "Please Enter Client Address\n";
    getline(cin, address);
    this->address = address;
    cout << "Please Enter Client Phone";
    cin >> phoneNumber;
    this->phoneNumber = phoneNumber;
    this->app = a;
//     this->account = new BankAccount(this);

}
Client ::Client(string name, string address, int phoneNumber , BankApplication* a)
{
    this->name = name;
    this->address = address;
    this->phoneNumber = to_string(phoneNumber);
    this->app = a;
}
void Client::createAccount(char type, double balance)
{
    int t = type - '0';
    this->account = new BankAccount(balance, app, t);
}


void Client::createAccount(int &ty, double &balance)
{
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving ; Type 1 or 2\n";
    cin >> ty;
    cout << "Please Enter the Starting Balance\n";
    cin >> balance;
    if (ty == 1)
        this->account = new BankAccount(balance, app, ty );
    // else if (type == 2)
    //     this->account = new SavingBankAccount(balance, this);
}

BankAccount Client::get_account() { return *account; }

void Client :: updateBalance(double nBalance)
{
    account->set_balance(nBalance);
}

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
