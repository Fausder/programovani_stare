#include "GeometricObject.h"
#include <iostream>

GeometricObject::GeometricObject()
    : obsah(0.0), obvod(0.0) 
{
    std::cout << "Konstruktor GeometricObject" << std::endl;
}

GeometricObject::~GeometricObject()
{
    std::cout << "Destruktor GeometricObject" << std::endl;
}

void GeometricObject::VypocetObsahu()
{
    obsah = 0.0; 
}

void GeometricObject::VypocetObvodu()
{
    obvod = 0.0; 
}

double GeometricObject::GetObsah()
{
    return obsah; 
}

double GeometricObject::GetObvod()
{
    return obvod;
}
