#pragma once

class Wallet
{
private:
	int capacity;
	int cash;
public:
	Wallet(int cap);
	int GetCash();	
	void Deposit(int money);
	void Withdraw(int money);
};