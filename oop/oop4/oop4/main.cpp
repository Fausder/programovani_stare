#include <iostream>
#include "KeyValue.h"
#include "KeyValues.h"

#include "Osoba.h"
#include "PolozkaFaktury.h"
#include "Faktura.h"


using namespace std;


int main()
{
	/*int N = 5;
	KeyValues* myKeyValues = new KeyValues(N);

	KeyValue* myKeyValue = myKeyValues->CreateObject(0, 0.5);
	cout << myKeyValue->getValue() << endl;

	for (int i = 1; i < N; i++)
	{
		myKeyValues->CreateObject(i, i + 0.5);
	}
	cout << myKeyValues->SearchObject(4)->getValue() << endl;

	cout << "pred odebranim:" << endl;
	myKeyValues->Print();
	cout << "po odebrani:" << endl;
	myKeyValues->RemoveObject(2);
	myKeyValues->Print();

	delete myKeyValues;

	//cout<< myKeyValues->GetKey() << endl;

*/
// prvni faktura
	Osoba zakaznik("Jan Novak", "Ostrava");
	Faktura faktura(1, zakaznik, 3);

	faktura.PridatPolozku("Notebook", 15000);
	faktura.PridatPolozku("Mys", 500);
	faktura.PridatPolozku("Klavesnice", 1000);



	cout << "Puvodni faktura 1:" << endl;
	faktura.Print();
	cout << "--------------------------------" << endl;

	faktura.UpravitPolozku("Mys", 420.27);
	faktura.OdebratPolozku("Notebook");

	cout << "Faktura 1 po uprave:" << endl;
	faktura.Print();
	cout << "--------------------------------" << endl;

//druha faktura
	Osoba zakaznik2("Petr Novak", "Praha");
	Faktura faktura2(2, zakaznik2, 4);

	faktura2.PridatPolozku("Monitor", 5000);
	faktura2.PridatPolozku("Tiskarna", 2000);
	faktura2.PridatPolozku("Jablko", 19);
	faktura2.PridatPolozku("Rohlik", 2.5);

	cout << "Puvodni faktura 2:" << endl;
	faktura2.Print();
	cout << "--------------------------------" << endl;

	faktura2.OdebratPolozku("Monitor");
	faktura2.OdebratPolozku("Tiskarna");
	faktura2.UpravitPolozku("Jablko", 20.98);
	faktura2.UpravitPolozku("Rohlik", 3);
	faktura2.PridatPolozku("Pivo", 25);
	cout << "Faktura 2 po uprave:" << endl;
	faktura2.Print();


	return 0;
}
