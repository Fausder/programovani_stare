#pragma once

/**
 * @file Core.h
 * @brief Definice třídy Core a výčtového typu CoreType
 * @author Filip Heider
 * @date 2025-05-10
 */

#include <queue>
#include "Task.h"

 /**
  * @brief Typy jader
  *
  * Tento výčtový typ definuje možné druhy výpočetních jader podle jejich výkonu.
  */
enum class CoreType
{
    HIGH,    ///< Vysoce výkonné jádro
    MEDIUM,  ///< Středně výkonné jádro
    LOW      ///< Nízkovýkonné jádro
};

/**
 * @brief Třída reprezentující jádro procesoru
 *
 * Tato třída simuluje chování výpočetního jádra procesoru, které může
 * zpracovávat úlohy různých typů. Každý typ jádra má optimální výkon
 * pro odpovídající typ úlohy.
 */
class Core
{
private:
    CoreType type;                 ///< Typ jádra určující jeho výkon
    std::queue<TaskType> queue;    ///< Fronta úloh čekajících na zpracování
    int currentTaskTime;           ///< Zbývající čas aktuální úlohy
    bool processing;               ///< Indikace, zda jádro zpracovává úlohu

    /**
     * @brief Inicializuje zpracování nové úlohy, pokud je to možné
     *
     * Tato metoda kontroluje, zda jsou ve frontě nějaké úlohy a zda jádro
     * aktuálně nezpracovává jinou úlohu. Pokud jsou tyto podmínky splněny,
     * začne zpracovávat první úlohu ve frontě.
     */
    void startProcessing();

public:
    /**
     * @brief Konstruktor jádra
     * @param t Typ jádra určující jeho výkon
     */
    Core(CoreType t);

    /**
     * @brief Přidá úlohu do fronty jádra
     *
     * Úloha je zařazena na konec fronty a začne se zpracovávat,
     * jakmile na ni přijde řada.
     *
     * @param taskType Typ úlohy k přidání
     */
    void addTask(TaskType taskType);

    /**
    * @brief Vrátí dobu zpracování úlohy na tomto jádru
    *
    * Optimální kombinace typu jádra a úlohy vyžaduje 1 jednotku času,
    * zatímco neoptimální kombinace vyžaduje 2 jednotky.
    *
    * @param taskType Typ úlohy
    * @return Doba zpracování (1 nebo 2 jednotky času)
    */
    int getProcessingTime(TaskType taskType) const;

    /**
     * @brief Posune simulaci o jednu časovou jednotku
     *
     * Tato metoda simuluje jednu časovou jednotku zpracování úlohy.
     * Pokud jádro zpracovává úlohu, sníží se zbývající čas o jednu jednotku.
     * Pokud tím úloha dosáhne nuly, je dokončena a odstraněna z fronty.
     *
     * @return True pokud byla dokončena úloha, jinak false
     */
    bool processTimeUnit();

    /**
     * @brief Zkontroluje, zda je jádro neaktivní (nemá žádné úlohy)
     * @return True pokud je jádro neaktivní (fronta je prázdná a žádná úloha se nezpracovává)
     */
    bool isIdle() const;

    /**
     * @brief Získání počtu úloh ve frontě
     * @return Počet úloh ve frontě
     */
    size_t getQueueSize() const;

    /**
     * @brief Získá typ jádra
     * @return Typ jádra (HIGH, MEDIUM nebo LOW)
     */
    CoreType getType() const;
};