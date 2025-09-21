#pragma once
#include "Cash.h"

class Croupier
{
private:
    Cash cash;

public:
    Croupier(double initialCash);
    Cash& GetCash();
    const Cash& GetCash() const; 
};

