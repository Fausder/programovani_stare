#include <iostream>
#include <string>
#include "scheduler.h"

int main() {
    Scheduler scheduler;

    std::string filename;
    std::cout << "Zadejte nazev vstupniho souboru: ";
    std::cin >> filename;

    if (!scheduler.loadTasks(filename)) {
        std::cerr << "Nelze nacist ulohy ze souboru." << std::endl;
        return 1;
    }

    int roundRobinTime = scheduler.simulateRoundRobin();
    int optimizedTime = scheduler.simulateOptimized();


    std::cout << "Vysledky simulace:" << std::endl;
    std::cout << "Round-robin: " << roundRobinTime << " casovych jednotek" << std::endl;
    std::cout << "Optimalizovany: " << optimizedTime << " casovych jednotek" << std::endl;
    std::cout << "Zlepseni: " << roundRobinTime - optimizedTime << " casovych jednotek (" 
        << (100.0 * (roundRobinTime - optimizedTime) / roundRobinTime) << "%)" << std::endl;

    return 0;
}