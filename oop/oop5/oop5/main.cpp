#include "Client.h"
#include "Account.h"
#include <iostream>

using namespace std;

int main()
{
    const int numClients = 8;
    Client clients[numClients] =
    {
        Client(1, "Klient 1"), Client(2, "Klient 2"), Client(3, "Klient 3"), Client(4, "Klient 4"),
        Client(5, "Klient 5"), Client(6, "Klient 6"), Client(7, "Klient 7"), Client(8, "Klient 8"),
    };

    Account accounts[numClients] =
    {
        Account(101, &clients[0], 0.01), Account(102, &clients[1]), Account(103, &clients[2], 0.015), Account(104, &clients[3]),
        Account(105, &clients[4], 0.025), Account(106, &clients[5], &clients[3], 0.02), Account(107, &clients[6]), Account(108, &clients[7], 0.03),
    };


    accounts[0].Deposit(1000);
    accounts[1].Deposit(2000);
    accounts[2].Deposit(1500);
    accounts[3].Deposit(3000);
    accounts[4].Deposit(2500);
    accounts[5].Deposit(1800);
    accounts[6].Deposit(2200);
    accounts[7].Deposit(2700);

	for (int i = 0; i < numClients; i++)
	{
		cout <<  clients[i].GetName() << " ma na uctu: " << accounts[i].GetBalance() << ",-" << endl;
	}

    int j = 3;
    if (accounts[j].Withdraw(3000)) 
    {
		cout << "Vyber z uctu " << accounts[j].GetNumber() << " byl uspesny." << endl;
	}
    else 
    {
        cout << "Vyber z uctu " << accounts[j].GetNumber() << " byl neuspesny." << endl;
    }

	for (int i = 0; i < numClients; i++)
	{
		accounts[i].AddInterest();
	}

	for (int i = 0; i < numClients; i++)
	{
		cout << clients[i].GetName() << " ma na uctu: " << accounts[i].GetBalance() << ",-" << endl;
	}
    cout << "Majitel uctu: " << accounts[5].GetNumber() << " je: " << accounts[5].GetOwner()->GetName() << endl;
	cout << "Partner uctu: " << accounts[5].GetNumber() << " je: " << accounts[5].GetPartner()->GetName() << endl;
    return 0;
}
