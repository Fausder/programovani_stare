#pragma once
#include <vector>
#include <string>
#include "core.h"

/**
 * @brief Tøída implementující plánovaè procesoru
 */
class Scheduler {
private:
    std::vector<TaskType> tasks;      ///< Seznam všech úloh
    Core highCore;                    ///< Vysoce výkonné jádro
    Core mediumCore;                  ///< Støednì výkonné jádro
    Core lowCore;                     ///< Nízkovýkonné jádro

    /**
    * @brief Resetuje stav jader pro novou dávku
    */
    void resetCores();

    /**
     * @brief Strategie rozdìlení úloh - round-robin
     * @param batchStart Index první úlohy v dávce
     */
    void distributeRoundRobin(size_t batchStart);

    /**
     * @brief Strategie rozdìlení úloh - optimalizovaná
     * @param batchStart Index první úlohy v dávce
     */
    void distributeOptimized(size_t batchStart);

    /**
    * @brief Zpracovává dávku úloh
    * @param batchStart Index první úlohy v dávce
    * @param distributionStrategy Funkce pro distribuci úloh mezi jádra
    * @return Poèet èasových jednotek pro dokonèení dávky
    */
    int processBatch(size_t batchStart, void (Scheduler::* distributionStrategy)(size_t));

public:
    /**
     * @brief Konstruktor plánovaèe
     */
    Scheduler();

    /**
     * @brief Naète úlohy ze souboru
     * @param filename Název souboru s úlohami
     * @return True pokud se podaøilo naèíst úlohy
     */
    bool loadTasks(const std::string& filename);

    /**
     * @brief Simuluje zpracování úloh pomocí round-robin algoritmu
     * @return Poèet èasových jednotek pro dokonèení všech úloh
     */
    int simulateRoundRobin();

    /**
     * @brief Simuluje zpracování úloh pomocí optimalizovaného algoritmu
     * @return Poèet èasových jednotek pro dokonèení všech úloh
     */
    int simulateOptimized();
};