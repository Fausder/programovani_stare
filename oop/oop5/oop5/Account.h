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
	Client owner;
	Client* partner;

public:
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	Account(int n, Client* c, Client* p);
	Account(int n, Client* c, Client* p, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	Client* GetPartner();
	bool Canwithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
};