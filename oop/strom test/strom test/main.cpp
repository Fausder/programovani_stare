#include <iostream>
#include "KVString.h"

int main() {
    int depth = 2; // Zmìòte hloubku podle potøeby
    KVString* tree = KVString::CreateTree(depth);

    tree->Print(); // Tisk stromu

    delete tree; // Uvolnìní pamìti
    return 0;
}
