#include  "KeyValue.h"
#include "KeyValues.h"
#include <iostream>

KeyValue::KeyValue(int key, double value)
{
	this->key = key;
	this->value = value;
}

int KeyValue::getKey()
{
	return this->key;
}

double KeyValue::getValue()
{
	return this->value;
}