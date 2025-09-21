#pragma once
#include <string>
using namespace std;
class Animal {
protected:
    string name;
    int age;
    double weight;
    string species;
public:
    Animal(const string& name, int age, double weight, const string& species);

    virtual ~Animal() = default;

    void Feed(double foodWeight);
    virtual void MakeSound() const;
    virtual void Move() const;      

    std::string GetName() const;
    int GetAge() const;
    double GetWeight() const;
    std::string GetSpecies() const;


};