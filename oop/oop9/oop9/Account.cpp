#include "Account.h"
#include "Client.h"

Account::Account(int n, Client* o)
	: number(n), owner(o), balance(0.0), interestRate(0.0) {
}

Account::Account(int n, Client* o, double ir)
	: number(n), owner(o), balance(0.0), interestRate(ir) {
}

int Account::GetNumber() {
	return number;
}
double Account::GetBalance() {
	return balance;
}
double Account::GetInterestRate() {
	return interestRate;
}
Client* Account::GetOwner() {
	return owner;
}

void Account::Deposit(double a) {
	balance += a;
}
bool Account::Withdraw(double a) {
	bool succes = false;
	if (this->CanWithdraw(a)) {
		balance -= a;
		succes = true;
	}
	return succes;
}
void Account::AddInterest() {
	balance += (balance * interestRate);
}

bool Account::CanWithdraw(double a) {
	return (a <= balance);
}
