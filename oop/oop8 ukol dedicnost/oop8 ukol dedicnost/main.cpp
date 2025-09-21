#include "Animal.h"
#include "Mammal.h"
#include "AquaticMammal.h"
#include <iostream>

using namespace std;

int main() {
   
    Animal animal("Pes ", 5, 20.0, "Neznamy druh");
    animal.Feed(2.5);
	cout << "--------------------------" << endl;

   
    Mammal mammal("Lev", 8, 190.0, "kratka srst");
    mammal.Feed(5.0);
    mammal.GroomFur();
	cout << "--------------------------" << endl;
   
    AquaticMammal dolphin("Delfin", 12, 150.0, "hladka kuze", true);
    dolphin.Feed(3.0);
    dolphin.Swim();
    dolphin.Dive();

    return 0;
}
