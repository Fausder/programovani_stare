#include "CreditAccount.h"
#include <iostream>

using namespace std;

CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o), credit(c)
{
	//cout << "CreditAccount constructor " << endl;
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir), credit(c)
{
	//cout << "CreditAccount constructor " << endl;
}

CreditAccount::~CreditAccount()
{
	cout << "CreditAccount destructor " << endl;
}

bool CreditAccount::Canwithdraw(double a)
{
	return (GetBalance() + credit) >= a;
}

bool CreditAccount::canWithdraw(double a)
{
	return Canwithdraw(a);
}
