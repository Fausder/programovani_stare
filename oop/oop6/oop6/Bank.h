#pragma once
#include "Account.h"
#include "PartnerAccount.h"
#include "Client.h"
#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    Client** clients;
    int clientsCount;


    Account** accounts;
    int accountsCount;
public:
    Bank(int c, int a);
    ~Bank();
    Client* GetClient(int c);
    Account* GetAccount(int n);

    Client* CreateClient(int c, string n);
    Account* CreateAccount(int n, Client* o);
    Account* CreateAccount(int n, Client* o, double ir);
    PartnerAccount* CreateAccount(int n, Client* o, Client* p);
    PartnerAccount* CreateAccount(int n, Client* o, Client* p, double ir);
    void AddInterest();
    void ChangeDefaultInterestRate(double newRate); 
    int maxAccounts;
};
