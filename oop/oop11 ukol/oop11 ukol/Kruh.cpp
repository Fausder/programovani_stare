#include "Kruh.h"
#include <iostream>

const double Pi = 3.14;
Kruh::Kruh(double r) : polomer(r)
{
    std::cout << "Konstruktor Kruh" << std::endl;
}

Kruh::~Kruh()
{
    std::cout << "Destruktor Kruh" << std::endl;
}

void Kruh::VypocetObsahu()
{
    obsah = Pi * polomer * polomer;
}

void Kruh::VypocetObvodu()
{
    obvod = 2 * Pi * polomer; 
}
