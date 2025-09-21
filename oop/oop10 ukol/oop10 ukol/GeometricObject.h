#pragma once

class GeometricObject
{
protected:
    double obsah;
    double obvod;

public:
    GeometricObject();
    ~GeometricObject();
    double GetObsah();
    double GetObvod();
    void VypocetObsahu();
    void VypocetObvodu();
};
