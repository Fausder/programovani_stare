#include "Account.h"
#include <iostream>
#include "Client.h"

using namespace std;

Account::Account(int n, Client* o) : number(n), owner(o), balance(0), interestRate(0)
{
	//cout << "Account constructor: " << n << endl;
}

Account::Account(int n, Client* o, double ir) : number(n), owner(o), balance(0), interestRate(ir)
{
	//cout << "Account constructor: " << n << endl;
}

Account::~Account()
{
	cout << "Account destructor " << endl;
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
	return owner;
}

bool Account::Canwithdraw(double a)
{
	return (a <= balance);
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
	else
	{
		cout << "Not enough balance!" << endl;
		return false;
	}
}

void Account::AddInterest()
{
	balance += balance * interestRate;
}