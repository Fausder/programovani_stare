#pragma once

#include <iostream>

using namespace std;

class KeyValue {
private:
	int key;
	double value;
	KeyValue* next;
public:
	KeyValue(int k, double v);
	~KeyValue();
	int GetKey();
	double GetValue();
	KeyValue* GetNext();
	KeyValue* CreateNext(int k, double v);


	void Print();
	void SetNext(KeyValue* next);

	static KeyValue* CreateLoop(int n);
	static KeyValue* CreateRecursive(int n);
	static KeyValue* GrowLoop(KeyValue* p1, int n);
	static KeyValue* GrowRecursive(KeyValue* l1, int n);
	static KeyValue* GetTail(KeyValue* m1);
	static KeyValue* DeleteAtPos(KeyValue* o1, int n);
};