#pragma once
#include "Account.h"
#include <iostream>

class CreditAccount : public Account
{
private:
    double credit;
public:
    CreditAccount(int n, Client* o, double c);
    CreditAccount(int n, Client* o, double ir, double c);
    virtual ~CreditAccount();

    virtual bool Canwithdraw(double a) override;
    virtual bool canWithdraw(double a) override;
};
