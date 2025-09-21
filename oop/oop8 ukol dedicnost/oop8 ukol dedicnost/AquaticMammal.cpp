#include "AquaticMammal.h"
#include <iostream>

AquaticMammal::AquaticMammal(const std::string& name, int age, double weight, const std::string& furType, bool canDive)
    : Mammal(name, age, weight, furType), canDive(canDive) {
}

void AquaticMammal::Swim() const {
    std::cout << name << " plave ve vode." << std::endl;
}

void AquaticMammal::Dive() const {
    if (canDive) {
        std::cout << name << " se potapi pod vodu." << std::endl;
    }
    else {
        std::cout << name << " se nemuze potapet." << std::endl;
    }
}

bool AquaticMammal::CanDive() const {
    return canDive;
}
