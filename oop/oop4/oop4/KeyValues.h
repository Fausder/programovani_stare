#pragma once
#include <iostream>
#include "KeyValue.h"
using namespace std;

class KeyValues
{
private:
	KeyValue** keyValues;
	int count;
	int size;
public:
	KeyValues(int n);
	~KeyValues();
	KeyValue* CreateObject(int key, double value);
	KeyValue* SearchObject(int key);
	int Count();

	KeyValue* RemoveObject(int key);
	void Print();
};