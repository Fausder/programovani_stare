#pragma once
#include <string>

using namespace std;

class PolozkaFaktury 
{
private:
    string nazev;
    double cena;
public:
    PolozkaFaktury() : nazev(""), cena(0.0) {}
    PolozkaFaktury(const string& nazev, double cena);
    string getNazev() const;
    double getCena() const;
    void setCena(double cena);
    string toString() const;
};
