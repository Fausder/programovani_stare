#include  "KeyValues.h"
#include "KeyValue.h"
#include <iostream>

KeyValues::KeyValues(int n)
{
	this->keyValues = new KeyValue*[n];
	this->count = 0;
	this->size = n;
}

KeyValues::~KeyValues()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->keyValues[i];
	}
	delete[] this->keyValues;
}

int KeyValues::Count()
{
	return this->count;
}

KeyValue* KeyValues::CreateObject(int key, double value)
{
	KeyValue *newObject = new KeyValue(key, value);
	this->keyValues[this->count] = newObject;
	this->count += 1;
	return newObject;
}

KeyValue* KeyValues::SearchObject(int key)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->keyValues[i]->getKey() == key)
		{
			return this->keyValues[i];
		}
	}
	return nullptr;
}

KeyValue* KeyValues::RemoveObject(int key) 
{
	for (int i = 0; i < this->count; i++) 
	{
		if (this->keyValues[i]->getKey() == key) 
		{
			KeyValue* removedObject = this->keyValues[i];
			for (int j = i; j < this->count - 1; j++) 
			{
				this->keyValues[j] = this->keyValues[j + 1];
			}
			this->count -= 1;
			return removedObject;
		}
	}
	return nullptr;
}

void KeyValues::Print()
{
	for (int i = 0; i < this->size; i++)
	{
		if (i < this->count && this->keyValues[i] != nullptr)
		{
			cout << "Index " << i << ": Key = " << this->keyValues[i]->getKey() << ", Value = " << this->keyValues[i]->getValue() << endl;
		}
		else
		{
			cout << "Index " << i << ": Empty" << endl;
		}
	}
}
