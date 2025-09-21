#include "Account.h"
#include "CreditAccount.h"
#include "Client.h"
#include "CreditAccount.h"

CreditAccount::CreditAccount(int n, Client* o, double c)
    : Account(n, o), credit(c) {
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c)
    : Account(n, o, ir), credit(c) {
}

bool CreditAccount::CanWithdraw(double a) {
    return (a <= (GetBalance() + credit));
}

