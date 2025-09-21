#include "Animal.h"
#include <iostream>

using namespace std;
Animal::Animal(const string& name, int age, double weight, const string& species)
    : name(name), age(age), weight(weight), species(species) {
}

void Animal::Feed(double foodWeight) {
    weight += foodWeight;
    cout << name << " byl nakrmen a nyni vazi " << weight << " kg." << endl;
}

void Animal::MakeSound() const {
    cout << name << " vydává zvuk." << endl;
}

void Animal::Move() const {
    cout << name << " se pohybuje." << endl;
}

std::string Animal::GetName() const {
    return name;
}

int Animal::GetAge() const {
    return age;
}

double Animal::GetWeight() const {
    return weight;
}

std::string Animal::GetSpecies() const {
    return species;
}
