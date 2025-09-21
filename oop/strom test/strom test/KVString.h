#ifndef KVSTRING_H
#define KVSTRING_H

#include <string>

using namespace std;

class KVString {
private:
    string key;
    string value;
    KVString* nextLeft;
    KVString* nextRight;

public:
    KVString(string k, string v);
    string GetKey();
    string GetValue();
    KVString* GetNextLeft();
    KVString* GetNextRight();
    void SetNextLeft(KVString* next);
    void SetNextRight(KVString* next);
    void Print(int depth = 0);
    static KVString* CreateTree(int depth);
};

#endif
