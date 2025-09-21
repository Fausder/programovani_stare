#pragma once
#include "Cash.h"
#include <string>
using namespace std;

class Gamer
{
private:
    string name;
    Cash cash;

public:
    Gamer();
    Gamer(string n, double initialCash);
    string GetName() const;
    Cash& GetCash();
    const Cash& GetCash() const; 
    Gamer& operator=(const Gamer& other); 
};
