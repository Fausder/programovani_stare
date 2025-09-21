#pragma once
#include "Client.h"
#include <iostream>

using namespace std;

class Account
{
private:
    int number;
    double balance;
    double interestRate;
    Client* owner;

public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);

    virtual ~Account() 
    {
        cout << "Destruktor Account" << endl;
    }

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    virtual bool CanWithdraw(double a);

    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};
