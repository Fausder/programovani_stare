#include <iostream>
#include "Kruh.h"
#include "Obdelnik.h"
#include "Ctverec.h"

using namespace std;

int main()
{
    const int pocetObjektu = 3;

    Kruh* kruh = new Kruh(3.0);
    Obdelnik* obdelnik = new Obdelnik(4.0, 5.0);
    Ctverec* ctverec = new Ctverec(8.0);

    GeometricObject* objekty[pocetObjektu];
    objekty[0] = kruh;
    objekty[1] = obdelnik;
    objekty[2] = ctverec;

    for (int i = 0; i < pocetObjektu; i++)
    {
        cout << "\n=== Objekt " << i + 1 << " ===" << endl;

        if (i == 0)
        {
            kruh->VypocetObsahu();
            kruh->VypocetObvodu();
        }
        else if (i == 1)
        {
            obdelnik->VypocetObsahu();
            obdelnik->VypocetObvodu();
        }
        else if (i == 2)
        {
            ctverec->VypocetObsahu();
            ctverec->VypocetObvodu();
        }

        cout << "Obsah: " << objekty[i]->GetObsah() << endl;
        cout << "Obvod: " << objekty[i]->GetObvod() << endl;
    }
    cout << endl;
    Kruh *a= kruh;
	a->VypocetObsahu();
    cout << a->GetObsah();
   
	cout << endl;
    GeometricObject* k = a;
    k->VypocetObsahu();
    cout << k->GetObsah();
	cout << endl;


    delete kruh;
    delete obdelnik;
    delete ctverec;

    return 0;
}