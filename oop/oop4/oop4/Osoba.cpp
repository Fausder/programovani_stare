#include "Osoba.h"

Osoba::Osoba(const string& jmeno, const string& adresa) : jmeno(jmeno), adresa(adresa) {}

string Osoba::getJmeno() const 
{
    return jmeno;
}

string Osoba::getAdresa() const 
{
    return adresa;
}

string Osoba::toString() const 
{
    return "Jmeno: " + jmeno + ", Adresa: " + adresa;
}

