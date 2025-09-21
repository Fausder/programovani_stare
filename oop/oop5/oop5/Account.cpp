#include "Account.h"
#include "Client.h"
#include <iostream>

using namespace std;

Account::Account(int n, Client* c) : owner(*c)
{
	number = n;
	balance = 0;
	interestRate = 0;
	partner = nullptr;
}

Account::Account(int n, Client* c, double ir) : owner(*c)
{
	number = n;
	balance = 0;
	interestRate = ir;
	partner = nullptr;
}

Account::Account(int n, Client* c, Client* p) : owner(*c)
{
	number = n;
	balance = 0;
	interestRate = 0;
	partner = p;
}

Account::Account(int n, Client* c, Client* p, double ir) : owner(*c)
{
	number = n;
	balance = 0;
	interestRate = ir;
	partner = p;
}

int Account::GetNumber()
{
	return number;
}

double Account::GetBalance()
{
	return balance;
}

double Account::GetInterestRate()
{
	return interestRate;
}

Client* Account::GetOwner()
{
	return &owner;
}

Client* Account::GetPartner()
{
	return partner;
}

bool Account::Canwithdraw(double a)
{
	return balance >= a;
}

void Account::Deposit(double a)
{
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
