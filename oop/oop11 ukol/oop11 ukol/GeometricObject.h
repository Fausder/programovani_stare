#pragma once

class GeometricObject
{
protected:
    double obsah;
    double obvod;
public:
    GeometricObject();
    virtual ~GeometricObject();
    virtual double GetObsah();
    virtual double GetObvod();
    virtual void VypocetObsahu();
    virtual void VypocetObvodu();
};
