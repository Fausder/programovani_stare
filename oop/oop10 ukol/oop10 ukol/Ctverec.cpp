#include "Ctverec.h"
#include <iostream>

Ctverec::Ctverec(double a) : strana(a)
{
    std::cout << "Konstruktor Ctverec" << std::endl;
}

Ctverec::~Ctverec()
{
    std::cout << "Destruktor Ctverec" << std::endl;
}

void Ctverec::VypocetObsahu()
{
    obsah = strana * strana; 
}

void Ctverec::VypocetObvodu()
{
    obvod = 4 * strana;
}
