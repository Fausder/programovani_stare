/**
 * @mainpage Dokumentace projektu Task Scheduler
 *
 * @section intro_sec Úvod
 * Tento projekt implementuje simulátor plánování úloh na vícejádrovém procesoru.
 * Simulátor obsahuje různé typy jader (HIGH, MEDIUM, LOW) a úlohy různých typů náročnosti.
 *
 * @section algorithm_sec Algoritmy plánování
 * V projektu jsou implementovány dva algoritmy plánování:
 * - **Round Robin**: Úlohy jsou přidělovány jádrům cyklicky bez ohledu na typ úlohy nebo jádra
 * - **Optimalizovaný**: Úlohy jsou přidělovány jádrům tak, aby se minimalizoval celkový čas zpracování
 *
 * @section usage_sec Použití programu
 * Program načítá úlohy ze vstupního souboru, kde první řádek obsahuje počet úloh
 * a následuje seznam znaků reprezentujících typy úloh (H, M, L).
 *
 * @section structure_sec Struktura projektu
 * Projekt se skládá z následujících tříd:
 * - Task: Reprezentuje výpočetní úlohu
 * - Core: Reprezentuje jádro procesoru
 * - Scheduler: Implementuje algoritmy plánování
 *
 * @author Filip Heider
 * @date 2025-05-10
 */

 /**
  * @file main.cpp
  * @brief Hlavní soubor projektu Task Scheduler
  * @author Filip Heider
  * @date 2025-05-10
  *
  * Tento soubor obsahuje funkci main, která demonstruje použití třídy Scheduler
  * pro načtení úloh ze souboru a porovnání dvou algoritmů plánování.
  */

#include <iostream>
#include <string>
#include "Scheduler.h"

using namespace std;

/**
 * @brief Hlavní funkce programu
 *
 * Tato funkce načte úlohy ze souboru, umístěného v adresáři programu, zadaného uživatelem,
 * spustí simulaci pomocí dvou různých algoritmů plánování
 * a porovná jejich výkonnost.
 *
 * @return 0 při úspěšném dokončení, 1 při chybě
 */
int main()
{
    Scheduler scheduler;

    string filename;
    cout << "Zadejte nazev vstupniho souboru (napr. cpu_input_large.txt): ";
    cin >> filename;

    if (!scheduler.loadTasks(filename))
    {
        cerr << "Nelze nacist ulohy ze souboru." << endl;
        return 1;
    }

    int roundRobinTime = scheduler.simulateRoundRobin();
    int optimizedTime = scheduler.simulateOptimized();


    cout << "Vysledky simulace:" << endl;
    cout << "Round-robin: " << roundRobinTime << " casovych jednotek" << endl;
    cout << "Optimalizovany: " << optimizedTime << " casovych jednotek" << endl;
    cout << "Zlepseni o " << roundRobinTime - optimizedTime << " casovych jednotek ("
        << (100.0 * (roundRobinTime - optimizedTime) / roundRobinTime) << "%)" << endl;

    return 0;
}