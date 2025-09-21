#include "Member.h"

Member::Member(int i, string n) : id(i), name(n) {}

int Member::GetID() {
    return id;
}

string Member::GetName() {
    return name;
}

