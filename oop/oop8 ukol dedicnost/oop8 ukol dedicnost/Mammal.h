#pragma once
#include "Animal.h"
using namespace std;

class Mammal : public Animal {
protected:
    string furType;

public:
    Mammal(const string& name, int age, double weight, const string& furType);
    void GroomFur() const;
    string GetFurType() const;
};
