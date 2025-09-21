#pragma once
#include "GeometricObject.h"

class Kruh : public GeometricObject
{
private:
    double polomer;

public:
    Kruh(double r);
    virtual void VypocetObsahu() override; 
    virtual void VypocetObvodu() override; 
    virtual ~Kruh();
};
