#pragma once

/**
 * @brief Výètový typ definující typy úloh
 */
enum class TaskType {
    HIGH,    ///< Nároèná úloha (H)
    MEDIUM,  ///< Støednì nároèná úloha (M)
    LOW      ///< Nenároèná úloha (L)
};

/**
 * @brief Tøída reprezentující výpoèetní úlohu
 */
class Task {
private:
    TaskType type;  ///< Typ úlohy

public:
    /**
     * @brief Konstruktor úlohy
     * @param t Typ úlohy
     */
    Task(TaskType t);

    /**
     * @brief Získá typ úlohy
     * @return Typ úlohy
     */
    TaskType getType() const;
};