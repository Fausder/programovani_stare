#pragma once
#include <string>
using namespace std;

class Member
{
private:
    int id;
    string name;

public:
    Member() : id(0), name("") {}
    Member(int i, string n);
    int GetID();
    string GetName();
};

