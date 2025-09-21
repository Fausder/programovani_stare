#pragma once
#include "GeometricObject.h"

class Ctverec : public GeometricObject
{
private:
    double strana;

public:
    Ctverec(double a);
    void VypocetObsahu(); 
    void VypocetObvodu();
    ~Ctverec();
};
