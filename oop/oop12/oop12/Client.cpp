#include "Client.h"
#include <iostream>

int Client::instanceCount = 0;

Client::Client(int number, const std::string& name) : number(number), name(name)
{
    instanceCount++;
    //std::cout << "Client konstruktor: " << name << std::endl;
}

Client::~Client()
{
    instanceCount--;
    //std::cout << "Client destruktor: " << name << std::endl;
}

int Client::GetInstanceCount()
{
    return instanceCount;
}

int Client::GetNumber() const
{
    return number;
}

std::string Client::GetName() const
{
    return name;
}
