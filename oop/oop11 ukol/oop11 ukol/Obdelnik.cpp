#include "Obdelnik.h"
#include <iostream>

Obdelnik::Obdelnik(double a, double b) : stranaA(a), stranaB(b)
{
    std::cout << "Konstruktor Obdelnik" << std::endl;
}

Obdelnik::~Obdelnik()
{
    std::cout << "Destruktor Obdelnik" << std::endl;
}

void Obdelnik::VypocetObsahu()
{
    obsah = stranaA * stranaB; 
}

void Obdelnik::VypocetObvodu()
{
    obvod = 2 * (stranaA + stranaB);
}
