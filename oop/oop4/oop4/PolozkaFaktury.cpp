#include "PolozkaFaktury.h"

PolozkaFaktury::PolozkaFaktury(const string& nazev, double cena) : nazev(nazev), cena(cena) {}

string PolozkaFaktury::getNazev() const 
{
    return nazev;
}

double PolozkaFaktury::getCena() const 
{
    return cena;
}

void PolozkaFaktury::setCena(double cena) 
{
    this->cena = cena;
}

string PolozkaFaktury::toString() const 
{
    return nazev + ": " + to_string(cena);
}
