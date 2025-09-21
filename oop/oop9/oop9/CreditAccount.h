#pragma once
#include "Account.h"
#include <iostream>

using namespace std;
class CreditAccount : public Account
{
private:
    double credit;

public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client* o, double ir, double c);

    virtual ~CreditAccount()
    {
       cout << "Destruktor CreditAccount" << endl;
    }

    bool CanWithdraw(double a);
};
