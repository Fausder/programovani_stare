#pragma once
#include <string>

class Client
{
private:
    int number;
    std::string name;
    static int instanceCount;
public:
    Client(int number, const std::string& name);
    ~Client();
    int GetNumber() const;
    std::string GetName() const;
    static int GetInstanceCount(); 
};
