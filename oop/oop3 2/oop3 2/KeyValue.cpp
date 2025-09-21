#include  "KeyValue.h"
#include <iostream>

KeyValue::KeyValue(int k, double v) {
	this->key = k;
	this->value = v;
	this->next = nullptr;
}

KeyValue::~KeyValue() {
	if (this->next != nullptr) 
	{
		delete this->next;
		this->next = nullptr;
	}
}

int KeyValue::GetKey() {
	return this->key;
}

double KeyValue::GetValue() {
	return this->value;
}


KeyValue* KeyValue::GetNext() {
	return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v) {
	this->next = new KeyValue(k, v);
	return this->next;
}

void KeyValue::SetNext(KeyValue* next) 
{
	this->next = next;
}

//print
void KeyValue::Print() 
{
	KeyValue* aktualni = this;
	while (aktualni != nullptr) 
	{
		cout << "Key: " << aktualni->key << ", Value: " << aktualni->value << endl;
		aktualni = aktualni->next;
	}
}

//create loop
KeyValue* KeyValue::CreateLoop(int n) 
{
if (n <= 0) 
{
	return nullptr;
}
KeyValue* prvni = new KeyValue(1, 1);
prvni->Print();

KeyValue* aktualni = prvni;
for (int i = 2; i <= n; i++) 
{
	aktualni->next = new KeyValue(i, i);
	aktualni = aktualni->next;
	aktualni->Print();
}
return prvni;
}

//Create recursive
int y = 0;
KeyValue* KeyValue::CreateRecursive(int n)
{
	y++;
	if (n <= 0)
	{
		return nullptr;
	}
	KeyValue* novy = new KeyValue(y, y);
	if (y<=n)
	{
		novy->Print();
		novy->next = CreateRecursive(n);
	}
	return novy;
}

//Grow loop
KeyValue* KeyValue::GrowLoop(KeyValue* p1, int n)
{
	if (n <= 0)
	{
		return p1;
	}

	KeyValue* aktualni = p1;
	while (aktualni->next != nullptr)
	{
		aktualni = aktualni->next;
	}
	
	for (int i = 1; i <= n; i++)
	{
		aktualni->next = new KeyValue(i, i);
		aktualni = aktualni->next;
	}
	return p1;
}

//Grow recursive
int x = 0;
KeyValue* KeyValue::GrowRecursive(KeyValue* l1, int n)
{
	if (n <= 0)
	{
		return l1; 
	}

	KeyValue* aktualni = l1;
	while (aktualni->next != nullptr)
	{
		aktualni = aktualni->next;
	}
	x++;
	KeyValue* novy = new KeyValue(x, x);
	aktualni->next = novy;
	return GrowRecursive(l1, n - 1);
}


//GetTail
KeyValue* KeyValue::GetTail(KeyValue* m1)
{
	KeyValue* aktualni = m1;
	while (aktualni->next != nullptr)
	{
		aktualni = aktualni->next;
	}
	return aktualni;
}

//DeleteAtPos
KeyValue* KeyValue::DeleteAtPos(KeyValue* o1, int n) 
{
	if (n <= 0 || o1 == nullptr) 
	{
		return o1;
	}

	KeyValue* aktualni = o1;
	KeyValue* predchozi = nullptr;

	if (n == 1) 
	{
		o1 = aktualni->next;
		aktualni->next = nullptr;
		delete aktualni;
		return o1;
	}

	for (int i = 1; i < n; i++)
	{
		predchozi = aktualni;
		aktualni = aktualni->next;
		if (aktualni == nullptr)
		{
			return o1;
		}
	}

	if (predchozi != nullptr) 
	{
		predchozi->next = aktualni->next;
	}
	aktualni->next = nullptr;
	delete aktualni;
	return o1;
}
