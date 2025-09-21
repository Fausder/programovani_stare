#include "Casino.h"
#include <iostream>
#include <ctime> 

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Casino casino(10000, 5000);

    Gamer gamer1("Petr", 2000);
    Gamer gamer2("Anna", 5000);

  
    casino.AddGamer(gamer1);
    casino.AddGamer(gamer2);

    casino.PrintBalances();
    cout << "------------------------------------------------" << endl;
    int pocet_hrani = 10;
    for (int i = 0; i < pocet_hrani; ++i) {
        
        casino.PlayAllGames(1000);
    }
	cout << "------------------------------------------------" << endl;
    casino.PrintBalances();

    //getchar();
    return 0;

}
