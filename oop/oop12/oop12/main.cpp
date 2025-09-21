#include <iostream>
#include <string>
#include "Client.h"
#include "AbstractAccount.h"
#include "CreditAccount.h"

using namespace std;

int main()
{
	Client *o = new Client(0, "Smith");
	CreditAccount *ca = new CreditAccount(1, o, 1000);
	AbstractAccount *aa = ca;
	delete aa;
	delete o;
	getchar();
	return 0;
}