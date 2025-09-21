#include <iostream>
#include "Kruh.h"
#include "Obdelnik.h"
#include "Ctverec.h"

using namespace std;

int main()
{
    const int pocetObjektu = 3;
    GeometricObject* objekty[pocetObjektu]; 

    objekty[0] = new Kruh(3.0);
    objekty[1] = new Obdelnik(4.0, 5.0);
    objekty[2] = new Ctverec(8.0);


    for (int i = 0; i < pocetObjektu; i++)
    {
        cout << "\n=== Objekt " << i + 1 << " ===" << endl;

        objekty[i]->VypocetObsahu();
        objekty[i]->VypocetObvodu();

        cout << "Obsah: " << objekty[i]->GetObsah() << endl;
        cout << "Obvod: " << objekty[i]->GetObvod() << endl;
    }

    for (int i = 0; i < pocetObjektu; i++)
    {
        delete objekty[i];
        objekty[i] = nullptr;
    }

    return 0;
}