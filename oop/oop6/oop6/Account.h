#pragma once
#include "Client.h"

class Account
{
private:
    int number;
    double balance;
    double interestRate;
    static int instanceCount;
    static double defaultInterestRate; 
public:
    Account(int n, Client* o, bool isPartOfPartner = false); 
    Account(int n, Client* o, double interestRate, bool isPartOfPartner = false);
    ~Account();
    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    bool Canwithdraw(double a);
    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
    void SetInterestRate(double newRate);

    static double GetDefaultInterestRate();
    static void SetDefaultInterestRate(double newRate); 
    static int GetInstanceCount();
protected:
    Client* owner;
    bool isPartOfPartnerAccount = false;
};
