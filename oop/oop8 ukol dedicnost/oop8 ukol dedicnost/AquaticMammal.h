#pragma once
#include "Mammal.h"
using namespace std;
class AquaticMammal : public Mammal {
private:
    bool canDive;

public:
    AquaticMammal(const string& name, int age, double weight, const string& furType, bool canDive);
    void Swim() const;
    void Dive() const;
    bool CanDive() const;
};
