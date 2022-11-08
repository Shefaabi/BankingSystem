#ifndef HEADER_FILE_NAME1
#define HEADER_FILE_NAME1

#include <vector>
#include "BankAccount.h"
#include "Client.h"

using namespace std;

class Client;

class BankApplication
{
private:
    vector<Client> clinet;
    vector<BankAccount> account;

public:
    BankApplication(){};
    void addClient();
    void lists();
    void menu();
    void displayMenu();
    void run();
    void forTesting();
    int validID(string idd);
    void withdrawDepositOperator(int cas);
    void balanceEditing(double nBalance , string id);



};

#endif
