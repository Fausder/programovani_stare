/**
 * @file Core.cpp
 * @brief Implementace třídy Core
 * @author Filip Heider
 * @date 2025-05-10
 */

#include "Core.h"

 /**
  * @brief Konstruktor jádra
  *
  * Inicializuje jádro zadaného typu a nastaví vnitřní stav.
  *
  * @param t Typ jádra určující jeho výkon
  */
Core::Core(CoreType t)
{
    this->type = t;
    this->currentTaskTime = 0;
    this->processing = false;
}

/**
 * @brief Přidá úlohu do fronty jádra
 *
 * Úloha je zařazena na konec fronty a začne se zpracovávat,
 * jakmile na ni přijde řada.
 *
 * @param taskType Typ úlohy k přidání
 */
void Core::addTask(TaskType taskType)
{
    queue.push(taskType);

    startProcessing();
}

/**
 * @brief Vrátí dobu zpracování úlohy na tomto jádru
 *
 * Optimální kombinace typu jádra a úlohy vyžaduje 1 jednotku času,
 * zatímco neoptimální kombinace vyžaduje 2 jednotky.
 *
 * @param taskType Typ úlohy
 * @return Doba zpracování (1 nebo 2 jednotky času)
 */
int Core::getProcessingTime(TaskType taskType) const
{
    if ((type == CoreType::HIGH && taskType == TaskType::HIGH) ||
        (type == CoreType::MEDIUM && taskType == TaskType::MEDIUM) ||
        (type == CoreType::LOW && taskType == TaskType::LOW)) {
        return 1;
    }
    return 2;
}

/**
 * @brief Inicializuje zpracování nové úlohy, pokud je to možné
 *
 * Tato metoda kontroluje, zda jsou ve frontě nějaké úlohy a zda jádro
 * aktuálně nezpracovává jinou úlohu. Pokud jsou tyto podmínky splněny,
 * začne zpracovávat první úlohu ve frontě.
 */
void Core::startProcessing()
{
    if (!queue.empty() && !processing)
    {
        TaskType taskType = queue.front();
        currentTaskTime = getProcessingTime(taskType);
        processing = true;
    }
}

/**
 * @brief Posune simulaci o jednu časovou jednotku
 *
 * Tato metoda simuluje jednu časovou jednotku zpracování úlohy.
 * Pokud jádro zpracovává úlohu, sníží se zbývající čas o jednu jednotku.
 * Pokud tím úloha dosáhne nuly, je dokončena a odstraněna z fronty.
 *
 * @return True pokud byla dokončena úloha, jinak false
 */
bool Core::processTimeUnit()
{
    if (queue.empty() && !processing)
    {
        return false;
    }

    startProcessing();
    currentTaskTime--;

    if (currentTaskTime <= 0)
    {
        queue.pop();
        processing = false;
        startProcessing();
        return true;
    }

    return false;
}

/**
 * @brief Zkontroluje, zda je jádro neaktivní (nemá žádné úlohy)
 * @return True pokud je jádro neaktivní (fronta je prázdná a žádná úloha se nezpracovává)
 */
bool Core::isIdle() const
{
    return queue.empty() && !processing;
}

/**
 * @brief Získání počtu úloh ve frontě
 * @return Počet úloh ve frontě
 */
size_t Core::getQueueSize() const
{
    return queue.size();
}

/**
 * @brief Získá typ jádra
 * @return Typ jádra (HIGH, MEDIUM nebo LOW)
 */
CoreType Core::getType() const
{
    return type;
}