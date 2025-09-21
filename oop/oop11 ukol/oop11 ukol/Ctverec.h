#pragma once
#include "GeometricObject.h"

class Ctverec : public GeometricObject
{
private:
    double strana;

public:
    Ctverec(double a);
    virtual void VypocetObsahu() override; 
    virtual void VypocetObvodu() override; 
    virtual ~Ctverec();
};
