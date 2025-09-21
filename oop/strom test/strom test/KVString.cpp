#include "KVString.h"
#include <iostream>

using namespace std;

KVString::KVString(string k, string v) : key(k), value(v), nextLeft(nullptr), nextRight(nullptr) {}

string KVString::GetKey() {
    return key;
}

string KVString::GetValue() {
    return value;
}

KVString* KVString::GetNextLeft() {
    return nextLeft;
}

KVString* KVString::GetNextRight() {
    return nextRight;
}

void KVString::SetNextLeft(KVString* next) {
    nextLeft = next;
}

void KVString::SetNextRight(KVString* next) {
    nextRight = next;
}

void KVString::Print(int depth) {
    // Pro lepší formátování použijeme tabulátory podle hloubky
    for (int i = 0; i < depth; ++i) {
        cout << "\t";
    }
    cout << key << endl;

    // Rekurzivnì tiskneme levý a pravý podstrom
    if (nextLeft) {
        nextLeft->Print(depth + 1);
    }
    if (nextRight) {
        nextRight->Print(depth + 1);
    }
}

KVString* KVString::CreateTree(int depth) {
    if (depth < 0) return nullptr;

    // Vytváøíme nový uzel na základì aktuální hloubky
    KVString* node = new KVString("node: " + to_string(depth), "value");

    // Rekurzivnì vytvoøíme levý a pravý podstrom
    node->SetNextLeft(CreateTree(depth - 1));
    node->SetNextRight(CreateTree(depth - 1));

    return node;
}
