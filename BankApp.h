#ifndef HEADER_FILE_NAME1
#define HEADER_FILE_NAME1

#include <vector>
#include "BankAccount.h"
#include "Client.h"
using namespace std;

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
};

#endif