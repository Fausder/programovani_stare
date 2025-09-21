#include "Cash.h"

Cash::Cash(double initialAmount) : amount(initialAmount) {}

double Cash::GetAmount() const {
    return amount;
}

void Cash::AddAmount(double value) {
    amount += value;
}

bool Cash::DeductAmount(double value) {
    if (amount >= value) {
        amount -= value;
        return true;
    }
    return false;
}






