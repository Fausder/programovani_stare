#pragma once
#include "GeometricObject.h"

class Obdelnik : public GeometricObject
{
private:
    double stranaA;
    double stranaB;

public:
    Obdelnik(double a, double b);
    virtual void VypocetObsahu() override; 
    virtual void VypocetObvodu() override; 
    virtual ~Obdelnik();
};
