#include  "KeyValue.h"
#include <iostream>

KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
}

int KeyValue::GetKey()
{
	return this->key;
}

double KeyValue::GetValue()
{
	return this->value;
}
void KeyValue::SayHi()
{
	std::cout << "Hi KeyValue" << std::endl;
}