#include  "Wallet.h"
#include <iostream>

Wallet::Wallet(int cap)
{
	this->capacity = cap;
	this->cash = 0;
}

int Wallet::GetCash()
{
	return this->cash;
	std::cout << "V penezence je: " << this->cash << ",-" << std::endl;
}

void Wallet::Deposit(int money)
{
	if (this->cash + money > this->capacity)
	{
		std::cout << "Mas plnou penezenku, vic se tam nevleze" << std::endl;
	}
	else
	{
		this->cash = money + cash;
		std::cout << "Vlozil jsi: " << money << ",-" << std::endl;
		std::cout << "Aktualni stav: " << this->cash << ",-" << std::endl;
	}
}

void Wallet::Withdraw(int money)
{
	if (this->cash < money)
	{
		std::cout << "Nemas dost penez v penezence" << std::endl;
	}
	else
	{
		this->cash = cash - money;
		std::cout << "Vybral jsi: " << money << ",-" << std::endl;
		std::cout << "Aktualni stav: " << this->cash << ",-" << std::endl;
	}
}