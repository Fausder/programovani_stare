#pragma once

class Cash
{
private:
    double amount;

public:
    Cash(double initialAmount);
    double GetAmount() const;
    void AddAmount(double value);
    bool DeductAmount(double value);
};






