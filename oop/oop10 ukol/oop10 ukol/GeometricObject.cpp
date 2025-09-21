#include "GeometricObject.h"
using namespace std;




GeometricObject::~GeometricObject()
{
}

GeometricObject::GeometricObject()
{
	this->obsah = 0;
	this->obvod = 0;
}
double GeometricObject::GetObsah()
{
	return this->obsah;
}
double GeometricObject::GetObvod()
{
	return this->obvod;
}
void GeometricObject::VypocetObsahu()
{
	this->obsah = 0;
}

void GeometricObject::VypocetObvodu()
{
	this->obvod = 0;
}
