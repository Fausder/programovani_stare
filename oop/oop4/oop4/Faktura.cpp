#include "Faktura.h"
#include <iostream>

Faktura::Faktura(int id, const Osoba& zakaznik, int maxPolozek) : id(id), zakaznik(zakaznik), maxPolozek(maxPolozek) 
{
    polozky = new PolozkaFaktury[maxPolozek];
    pocetPolozek = 0;
}

Faktura::~Faktura() 
{
    delete[] polozky;
}

void Faktura::PridatPolozku(const string& nazev, double cena) 
{
    if (pocetPolozek < maxPolozek) 
    {
        polozky[pocetPolozek] = PolozkaFaktury(nazev, cena);
        pocetPolozek++;
    }
    else 
    {
        cout << "Nelze pridat dalsi polozku, faktura je plna." << endl;
    }
}

void Faktura::OdebratPolozku(const string& nazev) 
{
    for (int i = 0; i < pocetPolozek; i++) 
    {
        if (polozky[i].getNazev() == nazev) 
        {
            for (int j = i; j < pocetPolozek - 1; j++) 
                {
                polozky[j] = polozky[j + 1];
            }
            pocetPolozek--;
            break;
        }
    }
}

void Faktura::UpravitPolozku(const string& nazev, double cena) 
{
    for (int i = 0; i < pocetPolozek; i++) 
    {
        if (polozky[i].getNazev() == nazev) 
        {
            polozky[i].setCena(cena);
            break;
        }
    }
}

double Faktura::CelkovaCena() const 
{
    double suma = 0;
    for (int i = 0; i < pocetPolozek; i++) 
    {
        suma += polozky[i].getCena();
    }
    return suma;
}

void Faktura::Print() const 
{
    cout << "ID Faktury: " << id << endl;
    cout << zakaznik.toString() << endl;
	cout << "Polozky:" << endl;
    for (int i = 0; i < pocetPolozek; i++) 
    {
        cout << polozky[i].toString() << endl;
    }
    cout << "Celkova cena: " << CelkovaCena() << ",-"<< endl;
}


