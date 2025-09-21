#pragma once
#include <queue>
#include "task.h"

/**
 * @brief Výètový typ definující typy jader
 */
enum class CoreType {
    HIGH,    ///< Vysoce výkonné jádro (Cortex-X2)
    MEDIUM,  ///< Støednì výkonné jádro (Cortex-A710)
    LOW      ///< Nízkovýkonné jádro (Cortex-A510)
};

/**
 * @brief Tøída reprezentující jádro procesoru
 */
class Core {
private:
    CoreType type;                 ///< Typ jádra
    std::queue<TaskType> queue;    ///< Fronta úloh
    int currentTaskTime;           ///< Zbývající èas aktuální úlohy
    bool processing;               ///< Indikace, zda jádro zpracovává úlohu

    /**
     * @brief Inicializuje zpracování nové úlohy, pokud je to možné
     */
    void startProcessing();

public:
    /**
     * @brief Konstruktor jádra
     * @param t Typ jádra
     */
    Core(CoreType t);

    /**
     * @brief Pøidá úlohu do fronty jádra
     * @param taskType Typ úlohy k pøidání
     */
    void addTask(TaskType taskType);

    /**
     * @brief Posune simulaci o jednu èasovou jednotku
     * @return True pokud byla dokonèena úloha, jinak false
     */
    bool processTimeUnit();

    /**
     * @brief Zkontroluje, zda je jádro neaktivní (nemá žádné úlohy)
     * @return True pokud je jádro neaktivní
     */
    bool isIdle() const;

    /**
     * @brief Vrátí dobu zpracování úlohy na tomto jádru
     * @param taskType Typ úlohy
     * @return Doba zpracování (1 nebo 2 jednotky èasu)
     */
    int getProcessingTime(TaskType taskType) const;

    /**
     * @brief Získání poètu úloh ve frontì
     * @return Poèet úloh ve frontì
     */
    size_t getQueueSize() const;

    /**
     * @brief Získá typ jádra
     * @return Typ jádra
     */
    CoreType getType() const;
};
