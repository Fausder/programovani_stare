#include <iostream>
#include "KVString.h"

using namespace std;

int main() {
    int depth = 4; // Zmìòte hloubku podle potøeby
    KVString* tree = KVString::CreateTree(depth);

    tree->Print(); // Tisk stromu

    delete tree; // Uvolnìní pamìti
    return 0;
}
