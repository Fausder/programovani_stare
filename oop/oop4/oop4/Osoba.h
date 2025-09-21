#pragma once
#include <string>

using namespace std;

class Osoba 
{
private:
    string jmeno;
    string adresa;
public:
    Osoba(const string& jmeno, const string& adresa);
    string getJmeno() const;
    string getAdresa() const;
    string toString() const;
};

