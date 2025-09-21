/**
 * @file Scheduler.cpp
 * @brief Implementace třídy Scheduler
 * @author Filip Heider
 * @date 2025-05-10
 */

#include "scheduler.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Konstruktor plánovače
 *
 * Inicializuje plánovač se třemi jádry různých typů.
 */
Scheduler::Scheduler() :
    highCore(CoreType::HIGH),
    mediumCore(CoreType::MEDIUM),
    lowCore(CoreType::LOW) {
}

/**
 * @brief Načte úlohy ze souboru
 *
 * Načte seznam úloh ze zadaného souboru. První řádek obsahuje
 * počet úloh, následuje seznam znaků H, M, L reprezentujících typy úloh.
 *
 * @param filename Název souboru s úlohami
 * @return True pokud se podařilo načíst úlohy, jinak false
 */
bool Scheduler::loadTasks(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Chyba: Nelze otevrit soubor " << filename << endl;
        return false;
    }

    int taskCount;
    file >> taskCount;

    if (file.fail())
    {
        cerr << "Chyba pri cteni poctu uloh!" << endl;
        return false;
    }

    tasks.clear();
    tasks.reserve(taskCount);

    char taskChar;
    int loadedTasks = 0;

    while (loadedTasks < taskCount && file >> taskChar)
    {
        TaskType taskType;
        switch (taskChar)
        {
        case 'H': taskType = TaskType::HIGH; break;
        case 'M': taskType = TaskType::MEDIUM; break;
        case 'L': taskType = TaskType::LOW; break;
        default:
            continue;
        }

        tasks.push_back(taskType);
        loadedTasks++;
    }

    file.close();
    return (loadedTasks > 0);
}

/**
 * @brief Resetuje stav jader pro novou dávku
 *
 * Inicializuje všechna jádra do výchozího stavu, aby byla připravena
 * pro zpracování nové dávky úloh.
 */
void Scheduler::resetCores()
{
    highCore = Core(CoreType::HIGH);
    mediumCore = Core(CoreType::MEDIUM);
    lowCore = Core(CoreType::LOW);
}

/**
 * @brief Strategie rozdělení úloh - round-robin
 *
 * Implementuje cyklické (round-robin) přiřazování úloh mezi jádra, kdy
 * úlohy jsou přidělovány postupně všem jádrům bez ohledu na jejich typ.
 * Informace o round-robin algoritmu jsem čerpal z: 
 * https://informatecdigital.com/cs/definice-a-p%C5%99%C3%ADklady-kruhov%C3%A9ho-pl%C3%A1nov%C3%A1n%C3%AD/ a
 * https://www.guru99.com/cs/round-robin-scheduling-example.html
 *
 * @param batchStart Index první úlohy v dávce
 */
void Scheduler::distributeRoundRobin(size_t batchStart)
{
    size_t remainingTasks = (tasks.size() - batchStart < 8) ? (tasks.size() - batchStart) : 8;

    for (size_t i = 0; i < remainingTasks; ++i)
    {
        TaskType taskType = tasks[batchStart + i];

        switch (i % 3)
        {
        case 0: highCore.addTask(taskType); break;
        case 1: mediumCore.addTask(taskType); break;
        case 2: lowCore.addTask(taskType); break;
        }
    }
}

/**
 * @brief Strategie rozdělení úloh - optimalizovaná
 *
 * Implementuje optimalizovanou strategii přidělování úloh jádrům,
 * která bere v úvahu typ úlohy a aktuální vytížení jader. Snaží se
 * přidělit úlohy odpovídajícím jádrům, ale zároveň udržet vyváženou zátěž.
 *
 * Algoritmus se snaží prioritně přidělit úlohu jádru stejného typu, ale
 * pokud je jádro přetížené, přidělí úlohu méně vytíženému jádru.
 *
 * @param batchStart Index první úlohy v dávce
 */
void Scheduler::distributeOptimized(size_t batchStart)
{
    size_t remainingTasks = (tasks.size() - batchStart < 8) ? (tasks.size() - batchStart) : 8;

    for (size_t i = 0; i < remainingTasks; i++)
    {
        TaskType taskType = tasks[batchStart + i];

        switch (taskType)
        {
        case TaskType::HIGH:
            if (highCore.getQueueSize() > mediumCore.getQueueSize() + 3)
                mediumCore.addTask(taskType);
            else if (highCore.getQueueSize() > lowCore.getQueueSize() + 3)
                lowCore.addTask(taskType);
            else
                highCore.addTask(taskType);
            break;

        case TaskType::MEDIUM:
            if (mediumCore.getQueueSize() > lowCore.getQueueSize() + 3)
                lowCore.addTask(taskType);
            else if (mediumCore.getQueueSize() > highCore.getQueueSize() + 3)
                highCore.addTask(taskType);
            else
                mediumCore.addTask(taskType);
            break;

        case TaskType::LOW:
            if (lowCore.getQueueSize() > mediumCore.getQueueSize() + 3)
                mediumCore.addTask(taskType);
            else if (lowCore.getQueueSize() > highCore.getQueueSize() + 3)
                highCore.addTask(taskType);
            else
                lowCore.addTask(taskType);
            break;
        }
    }
}

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
int Scheduler::processBatch(size_t batchStart, void (Scheduler::* distributionStrategy)(size_t))
{
    resetCores();
    (this->*distributionStrategy)(batchStart);
    int timeUnits = 0;
    bool allIdle = false;

    while (!allIdle)
    {
        timeUnits++;

        highCore.processTimeUnit();
        mediumCore.processTimeUnit();
        lowCore.processTimeUnit();

        allIdle = highCore.isIdle() && mediumCore.isIdle() && lowCore.isIdle();

        size_t remainingTasks = (tasks.size() - batchStart < 8) ? (tasks.size() - batchStart) : 8;
        int maxTimeUnits = static_cast<int>(remainingTasks * 2 + 1);
        if (timeUnits > maxTimeUnits)
        {
            break;
        }
    }
    return timeUnits;
}

/**
 * @brief Simuluje zpracování úloh pomocí round-robin algoritmu
 *
 * Simuluje zpracování všech úloh pomocí round-robin algoritmu, kdy úlohy
 * jsou přidělovány cyklicky mezi jádra bez ohledu na jejich typ.
 *
 * @return Počet časových jednotek pro dokončení všech úloh
 */
int Scheduler::simulateRoundRobin()
{
    int totalTime = 0;
    size_t batchSize = 8;

    for (size_t i = 0; i < tasks.size(); i += batchSize)
    {
        totalTime += processBatch(i, &Scheduler::distributeRoundRobin);
    }
    return totalTime;
}

/**
 * @brief Simuluje zpracování úloh pomocí optimalizovaného algoritmu
 *
 * Simuluje zpracování všech úloh pomocí optimalizovaného algoritmu, který
 * bere v úvahu typy úloh a jader pro efektivnější přidělování.
 *
 * @return Počet časových jednotek pro dokončení všech úloh
 */
int Scheduler::simulateOptimized()
{
    int totalTime = 0;
    size_t batchSize = 8;

    for (size_t i = 0; i < tasks.size(); i += batchSize)
    {
        totalTime += processBatch(i, &Scheduler::distributeOptimized);
    }
    return totalTime;
}