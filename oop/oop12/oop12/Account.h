#pragma once
#include "Client.h"
#include "AbstractAccount.h"

class Account : public AbstractAccount
{
private:
    int number;
    double balance;
    double interestRate;

	Client* owner;
public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);
    virtual ~Account();

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    virtual bool Canwithdraw(double a);

    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};
