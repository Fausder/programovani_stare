#include "Mammal.h"
#include <iostream>


using namespace std;
Mammal::Mammal(const string& name, int age, double weight, const string& furType)
    : Animal(name, age, weight, "Savci"), furType(furType) {
}


void Mammal::GroomFur() const {
    cout << name << " ma srst typu " << furType << " a byla osetrena." << endl;
}

string Mammal::GetFurType() const {
    return furType;
}
