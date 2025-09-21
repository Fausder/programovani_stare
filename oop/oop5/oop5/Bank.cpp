#include "Account.h"
#include "Client.h"
#include "Bank.h"
#include <iostream>

using namespace std;

Bank::Bank(int c, int a)
{
	clients = new Client * [c];
	clientsCount = 0;
	accounts = new Account * [a];
	accountsCount = 0;
}

Bank::~Bank()
{
	for (int i = 0; i < clientsCount; i++)
	{
		delete clients[i];
	}
	delete[] clients;
	for (int i = 0; i < accountsCount; i++)
	{
		delete accounts[i];
	}
	delete[] accounts;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < clientsCount; i++)
	{
		if (clients[i]->GetCode() == c)
		{
			return clients[i];
		}
	}
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->GetNumber() == n)
		{
			return accounts[i];
		}
	}
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	Client* client = GetClient(c);
	if (client != nullptr)
	{
		return client;
	}
	if (clientsCount == 10)
	{
		return nullptr;
	}
	client = new Client(c, n);
	clients[clientsCount] = client;
	clientsCount++;
	return client;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	Account* account = GetAccount(n);
	if (account != nullptr)
	{
		return account;
	}
	if (accountsCount == 10)
	{
		return nullptr;
	}
	account = new Account(n, c);
	accounts[accountsCount] = account;
	accountsCount++;
	return account;
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	Account* account = GetAccount(n);
	if (account != nullptr)
	{
		return account;
	}
	if (accountsCount == 10)
	{
		return nullptr;
	}
	account = new Account(n, c, ir);
	accounts[accountsCount] = account;
	accountsCount++;
	return account;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
	Account* account = GetAccount(n);
	if (account != nullptr)
	{
		return account;
	}
	if (accountsCount == 10)
	{
		return nullptr;
	}
	account = new Account(n, c, p);
	accounts[accountsCount] = account;
	accountsCount++;
	return account;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	Account* account = GetAccount(n);
	if (account != nullptr)
	{
		return account;
	}
	if (accountsCount == 10)
	{
		return nullptr;
	}
	account = new Account(n, c, p, ir);
	accounts[accountsCount] = account;
	accountsCount++;
	return account;
}

void Bank::AddInterest()
{
	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i]->AddInterest();
	}
}