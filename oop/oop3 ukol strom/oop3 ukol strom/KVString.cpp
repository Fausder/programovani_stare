#include "KVString.h"
#include <iostream>

using namespace std;

KVString::KVString(std::string k, std::string v) 
{
    this->key = k;
    this->value = v;
    this->nextLeft = nullptr;
    this->nextRight = nullptr;
}

KVString::~KVString() 
{
    if (this->nextLeft != nullptr) 
    {
        delete this->nextLeft;
        this->nextLeft = nullptr;
    }
    if (this->nextRight != nullptr) 
    {
        delete this->nextRight;
        this->nextRight = nullptr;
    }
}

string KVString::GetKey() 
{
    return this->key;
}

string KVString::GetValue() 
{
    return this->value;
}


KVString* KVString::GetNextLeft() 
{
    return this->nextLeft;
}

KVString* KVString::GetNextRight() 
{
    return this->nextRight;
}


void KVString::SetNextLeft(KVString* next) 
{
    this->nextLeft = next;
}

void KVString::SetNextRight(KVString* next) 
{
    this->nextRight = next;
}


void KVString::PrintHelper(KVString* node, int depth) 
{
    if (node == nullptr) 
    {
        return;
    }
    PrintHelper(node->GetNextRight(), depth + 1);
    for (int i = 0; i < depth; ++i) 
    {
        cout << "\t";
    }
    cout << node->GetKey() << std::endl;
    PrintHelper(node->GetNextLeft(), depth + 1);
}


void KVString::Print() 
{
    PrintHelper(this, 0);
}


KVString* KVString::CreateTreeHelper(int depth, int maxDepth) 
{
    if (depth > maxDepth) 
    {
        return nullptr;
    }

    KVString* node = new KVString("node: " + to_string (depth), "value");
    node->SetNextLeft(CreateTreeHelper(depth + 1, maxDepth));
    node->SetNextRight(CreateTreeHelper(depth + 1, maxDepth));
    return node;
}


KVString* KVString::CreateTree(int n) 
{
    if (n <= 0) 
    {
        return nullptr;
    }
    KVString* root = new KVString("root", "value");
    return root->CreateTreeHelper(0, n - 1);
}
