#pragma once
#include "GeometricObject.h"

class Kruh : public GeometricObject
{
private:
    double polomer;

public:
    Kruh(double r);
    void VypocetObsahu(); 
    void VypocetObvodu(); 
    ~Kruh();
};
