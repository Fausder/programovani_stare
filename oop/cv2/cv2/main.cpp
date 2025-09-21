#include <iostream>
#include "KeyValue.h"
#include "Wallet.h"
#include "PersonRecord.h"

using namespace std;

void DemoKeyValue() 
{
	KeyValue kv1(1, 1.5);		//int cislo = 10; je stejný princip
	cout << kv1.GetValue() << endl;

	KeyValue* kv2 = new KeyValue(2, 2.5); // dynamicky alokovaný objekt
	cout << kv2->GetValue() << endl;
}

void DemoWallet()
{
	Wallet* w = new Wallet(100);
	w->Deposit(50);
	w->GetCash();
	w->Withdraw(150);
	w->Withdraw(25);
}

void PersonRecordDemo()
{
	PersonRecord* p = new PersonRecord("Pepa", "881206/1434");

	Sex s = p->GetSex();
	if (s == 1)
	{
		cout << "Jedna se o zenu jmenem " << p->GetName() << " s rodnym cislem " << p->GetBirthDate() << endl;
	}
	else
	{
		cout << "Jedna se o muze jmenem " << p->GetName() << " s rodnym cislem " << p->GetBirthDate() << endl;
	}

	cout << "Ustalene datum narozeni: " << p->GetBirthDate().substr(4, 2) << "." << p->GetBirthDate().substr(2, 2) << "." << p->GetBirthDate().substr(0, 2) << endl;
	cout << "Mesic narozeni: " << p->GetBirthDate().substr(2, 2) << endl;
	cout << "Den narozeni: " << p->GetBirthDate().substr(4, 2) << endl;
}

int main()
{
	PersonRecordDemo();
	DemoKeyValue();
	DemoWallet();	
	return 0;
}