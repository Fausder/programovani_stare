#pragma once
#include <iostream>
using namespace std;

class KeyValue
{
private:
	int key;
	double value;
public:
	KeyValue(int key, double value);
	int getKey();
	double getValue();
};