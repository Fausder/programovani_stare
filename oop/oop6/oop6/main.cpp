#include "Account.h"
#include "Bank.h"
#include "Client.h"
#include <iostream>

using namespace std;

int main()
{


    Bank bank(10, 10);

   
    Client* client1 = bank.CreateClient(1, "Alice");
    Client* client2 = bank.CreateClient(2, "Bob");
	Client* client3 = bank.CreateClient(3, "Jan");


    cout << "Pocet klientu po vytvoreni: " << Client::GetInstanceCount() << endl;

  
    Account* account1 = bank.CreateAccount(1, client1);
	Account* account2 = bank.CreateAccount(2, client2);
    Account* account3 = bank.CreateAccount(3, client3, 0.05);

	PartnerAccount* partnerAccount = bank.CreateAccount(3, client1, client2);

    cout << "Pocet uctu po vytvoreni: " << Account::GetInstanceCount() << endl;

   
    cout << "Puvodni def. urokova sazba: " << Account::GetDefaultInterestRate() << endl;


    bank.ChangeDefaultInterestRate(0.02);

    cout << "Nova def. urokova sazba: " << Account::GetDefaultInterestRate() << endl;

    cout << "Urokova sazba uctu 1: " << account1->GetInterestRate() << endl;
    cout << "Urokova sazba uctu 2: " << account2->GetInterestRate() << endl;
	cout << "Urokova sazba uctu 3 s nastavenou urok. sazbou: " << account3->GetInterestRate() << endl;


    account1->Deposit(1000);
    account2->Deposit(2000);

    cout << "Zustatek uctu 1 po vkladu: " << account1->GetBalance() << endl;
    cout << "Zustatek uctu 2 po vkladu: " << account2->GetBalance() << endl;

    account1->Withdraw(500);
    account2->Withdraw(1000);

    cout << "Zustatek uctu 1 po vyberu: " << account1->GetBalance() << endl;
    cout << "Zustatek uctu 2 po vyberu: " << account2->GetBalance() << endl;

    bank.AddInterest();

    cout << "Zustatek uctu 1 po pridani uroku: " << account1->GetBalance() << endl;
    cout << "Zustatek uctu 2 po pridani uroku: " << account2->GetBalance() << endl;



    return 0;
}
