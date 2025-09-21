#include <iostream>
#include "Client.h"
#include "Account.h"
#include "CreditAccount.h"

using namespace std;

int main()
{
    Client* o = new Client(0, "Smith");
    CreditAccount* ca = new CreditAccount(1, o, 1000);

    cout << ca->CanWithdraw(1000) << endl;

    Account* a = ca; 
    cout << a->CanWithdraw(1000) << endl;

    cout << ca->Withdraw(1000) << endl;

    a = nullptr;
    delete ca; 

    getchar();
    return 0;
}
