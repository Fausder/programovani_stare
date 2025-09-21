#pragma once
#include <iostream>

using namespace std;

class Client
{
private:
	int number;
	string name;
	static int instanceCount;
public:
	Client(int number, const std::string& name);
	~Client();
	static int GetInstanceCount();
	int GetNumber() const;
	std::string GetName() const;
};
