#include "Account.h"
#include <iostream>

using namespace std;
double Account::defaultInterestRate = 0.01;
int Account::instanceCount = 0;

Account::Account(int n, Client* o, bool isPartOfPartner)
    : number(n), owner(o), balance(0), interestRate(defaultInterestRate), isPartOfPartnerAccount(isPartOfPartner) {
    ++instanceCount;
    if (!isPartOfPartnerAccount) { 
        std::cout << "Account konstruktor: " << owner->GetName() << std::endl;
    }
}

Account::Account(int number, Client* owner, double interestRate, bool isPartOfPartner)
    : number(number), balance(0), interestRate(interestRate), owner(owner), isPartOfPartnerAccount(isPartOfPartner) {
    ++instanceCount;
    if (!isPartOfPartnerAccount) { 
        std::cout << "Account konstruktor (s vlastni urokovou sazbou): " << owner->GetName() << std::endl;
    }
}



Account::~Account() {
    --instanceCount;
    if (!isPartOfPartnerAccount) { 
        std::cout << "Account destruktor: " << owner->GetName() << std::endl;
    }
}

int Account::GetInstanceCount() {
    return instanceCount;
}

double Account::GetDefaultInterestRate()
{
    return defaultInterestRate;
}

void Account::SetDefaultInterestRate(double newRate)
{
    defaultInterestRate = newRate;
}

int Account::GetNumber()
{
    return number;
}

double Account::GetBalance()
{
    if (this == nullptr)
    {
        return 0;
    }
    return balance;
}

double Account::GetInterestRate()
{
    if (this == nullptr)
    {
        return 1;
    }
    return interestRate;
}

Client* Account::GetOwner()
{
    return owner;
}

bool Account::Canwithdraw(double a)
{
    if (this == nullptr)
    {
        return false;
    }
    return a <= balance;
}


void Account::Deposit(double a)
{
    if (this == nullptr)
    {
        return;
    }
    balance += a;
}

bool Account::Withdraw(double a)
{
    if (Canwithdraw(a))
    {
        balance -= a;
        return true;
    }
    return false;
}

void Account::AddInterest()
{
    balance += balance * interestRate;
}
void Account::SetInterestRate(double newRate) {
    interestRate = newRate; 
}
