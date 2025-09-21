#pragma once
#include <string>
#include <iostream>
using namespace std;

class Account; 

class Client
{
private:
    int id;
    string name;
    string address;

public:
    Client(int clientId, const string& clientName);
    Client(int clientId, const string& clientName, const string& clientAddress);

 

    int GetId() const;
    string GetName() const;
    string GetAddress() const;

    void SetName(const string& newName);
    void SetAddress(const string& newAddress);
};
