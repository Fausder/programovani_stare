#include "Account.h"
#include "Bank.h"
#include "PartnerAccount.h"
#include "Client.h"
#include <iostream>
#include <string>
using namespace std;




Bank::~Bank() {
	for (int i = 0; i < accountsCount; i++) {
		delete accounts[i];
	}
	delete[] accounts;

	for (int i = 0; i < clientsCount; i++) {
		delete clients[i];
	}
	delete[] clients;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetNumber() == c)
		{
			return this->clients[i];
		}
	}
	return nullptr;
}
Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		if (this->accounts[i]->GetNumber() == n)
		{
			return this->accounts[i];
		}
	}
	return nullptr;
}
Client* Bank::CreateClient(int c, string n)
{
	Client* client = new Client(c, n);
	this->clients[this->clientsCount] = client;
	this->clientsCount++;
	return client;
}

Bank::Bank(int c, int a) : clientsCount(0), accountsCount(0), maxAccounts(a)
{
	clients = new Client * [c];
	accounts = new Account * [a];

	for (int i = 0; i < a; i++) {
		accounts[i] = nullptr;
	}
}
Account* Bank::CreateAccount(int n, Client* o)
{
	if (accountsCount >= maxAccounts) {
		std::cerr << "Chyba: Nelze vytvorit ucet " << n << ". Kapacita je plna." << std::endl;
		return nullptr;
	}

	accounts[accountsCount] = new Account(n, o);
	accountsCount++; 
	return accounts[accountsCount - 1];
}


Account* Bank::CreateAccount(int n, Client* o, double ir)
{
	Account* account = new Account(n, o, ir);
	this->accounts[this->accountsCount] = account;
	this->accountsCount++;
	return account;
}
PartnerAccount* Bank::CreateAccount(int n, Client* o, Client* p)
{
	if (accountsCount >= maxAccounts) {
		cerr << "Chyba: Nelze vytvorit partner account " << n << ". Kapacita je plna." << endl;
		return nullptr;
	}


	PartnerAccount* account = new PartnerAccount(n, o, p);
	accounts[accountsCount] = account; 
	accountsCount++;
	return account; 
}

PartnerAccount* Bank::CreateAccount(int n, Client* o, Client* p, double ir)
{
	if (accountsCount >= maxAccounts) {
		cerr << "Chyba: Nelze vytvorit partner account " << n << ". Kapacita je plna." << endl;
		return nullptr;
	}

	
	PartnerAccount* account = new PartnerAccount(n, o, p, ir);
	accounts[accountsCount] = account; 
	accountsCount++;
	return account; 
}


void Bank::ChangeDefaultInterestRate(double newRate)
{
	double oldRate = Account::GetDefaultInterestRate();
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] != nullptr && accounts[i]->GetInterestRate() == oldRate)
		{
			accounts[i]->SetInterestRate(newRate);
		}
	}
	Account::SetDefaultInterestRate(newRate);
}


void Bank::AddInterest()
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] != nullptr) 
		{
			accounts[i]->AddInterest(); 
		}
	}
}
