#pragma once

/**
 * @file Scheduler.h
 * @brief Definice třídy Scheduler pro plánování úloh na více jader
 * @author Filip Heider
 * @date 2025-05-10
 */

#include <vector>
#include <string>
#include "Core.h"

 /**
  * @brief Třída implementující plánovač procesoru
  *
  * Tato třída poskytuje nástroje pro plánování a simulaci zpracování úloh
  * na třech různých typech jader procesoru. Implementuje dva algoritmy plánování:
  * 1. Round-robin - cyklické přidělování úloh na jádra
  * 2. Optimalizovaný - přidělování úloh na jádra podle typu a zatížení
  */
class Scheduler
{
private:
    std::vector<TaskType> tasks;      ///< Seznam všech úloh k zpracování
    Core highCore;                    ///< Vysoce výkonné jádro (typ HIGH)
    Core mediumCore;                  ///< Středně výkonné jádro (typ MEDIUM)
    Core lowCore;                     ///< Nízkovýkonné jádro (typ LOW)

    /**
    * @brief Zpracovává dávku úloh podle zvolené strategie
    *
    * Metoda simuluje zpracování dávky úloh (až 8) vybranou strategií
    * a vrátí celkový počet časových jednotek potřebných k jejich dokončení.
    *
    * @param batchStart Index první úlohy v dávce
    * @param distributionStrategy Funkce pro distribuci úloh mezi jádra
    * @return Počet časových jednotek pro dokončení dávky
    */
    int processBatch(size_t batchStart, void (Scheduler::* distributionStrategy)(size_t));

    /**
     * @brief Strategie rozdělení úloh - round-robin
     *
     * Implementuje cyklické (round-robin) přiřazování úloh mezi jádra, kdy
     * úlohy jsou přidělovány postupně všem jádrům bez ohledu na jejich typ.
     *
     * @param batchStart Index první úlohy v dávce
     */
    void distributeRoundRobin(size_t batchStart);

    /**
     * @brief Strategie rozdělení úloh - optimalizovaná
     *
     * Implementuje optimalizovanou strategii přidělování úloh jádrům,
     * která bere v úvahu typ úlohy a aktuální vytížení jader. Snaží se
     * přidělit úlohy odpovídajícím jádrům, ale zároveň udržet vyváženou zátěž.
     *
     * @param batchStart Index první úlohy v dávce
     */
    void distributeOptimized(size_t batchStart);

    /**
     * @brief Resetuje stav jader pro novou dávku
     *
     * Inicializuje všechna jádra do výchozího stavu, aby byla připravena
     * pro zpracování nové dávky úloh.
     */
    void resetCores();

public:
    /**
     * @brief Konstruktor plánovače
     *
     * Inicializuje plánovač se třemi jádry různých typů.
     */
    Scheduler();

    /**
     * @brief Načte úlohy ze souboru
     *
     * Načte seznam úloh ze zadaného souboru. První řádek obsahuje
     * počet úloh, následuje seznam znaků H, M, L reprezentujících typy úloh.
     *
     * @param filename Název souboru s úlohami
     * @return True pokud se podařilo načíst úlohy, jinak false
     */
    bool loadTasks(const std::string& filename);

    /**
     * @brief Simuluje zpracování úloh pomocí round-robin algoritmu
     *
     * Simuluje zpracování všech úloh pomocí round-robin algoritmu, kdy úlohy
     * jsou přidělovány cyklicky mezi jádra bez ohledu na jejich typ.
     *
     * @return Počet časových jednotek pro dokončení všech úloh
     */
    int simulateRoundRobin();

    /**
     * @brief Simuluje zpracování úloh pomocí optimalizovaného algoritmu
     *
     * Simuluje zpracování všech úloh pomocí optimalizovaného algoritmu, který
     * bere v úvahu typy úloh a jader pro efektivnější přidělování.
     *
     * @return Počet časových jednotek pro dokončení všech úloh
     */
    int simulateOptimized();
};