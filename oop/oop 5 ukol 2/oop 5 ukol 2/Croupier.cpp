#include "Croupier.h"

Croupier::Croupier(double initialCash) : cash(initialCash) {}

Cash& Croupier::GetCash() {
    return cash;
}

const Cash& Croupier::GetCash() const {
    return cash;
}

