#pragma once
#include <string>
#include "Osoba.h"
#include "PolozkaFaktury.h"

using namespace std;

class Faktura 
{
private:
    int id;
    Osoba zakaznik;
    PolozkaFaktury* polozky;
    int pocetPolozek;
    int maxPolozek;
public:
    Faktura(int id, const Osoba& zakaznik, int maxPolozek);
    ~Faktura();
    void PridatPolozku(const string& nazev, double cena);
    void OdebratPolozku(const string& nazev);
    void UpravitPolozku(const string& nazev, double cena);
    double CelkovaCena() const;
    void Print() const;
};


