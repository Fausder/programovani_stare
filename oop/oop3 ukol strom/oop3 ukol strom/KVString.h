#pragma once

#include <iostream>
#include <string>

using namespace std;

class KVString {
private:
    string key;
    string value;
    KVString* nextLeft;
    KVString* nextRight;

    void PrintHelper(KVString* node, int depth);
    KVString* CreateTreeHelper(int depth, int maxDepth);

public:
    KVString(string k, string v);
    ~KVString();
    string GetKey();
    string GetValue();
    KVString* GetNextLeft();
    KVString* GetNextRight();

    void SetNextLeft(KVString* next);
    void SetNextRight(KVString* next);
    void Print();
    static KVString* CreateTree(int n);
};
