#include "Gamer.h"

Gamer::Gamer() : name(""), cash(0) {}

Gamer::Gamer(string n, double initialCash) : name(n), cash(initialCash) {}

string Gamer::GetName() const {
    return name;
}

Cash& Gamer::GetCash() {
    return cash;
}

const Cash& Gamer::GetCash() const {
    return cash;
}

Gamer& Gamer::operator=(const Gamer& other) {
    if (this != &other) {
        name = other.name;
        cash = other.cash;
    }
    return *this;
}
