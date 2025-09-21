#pragma once

/**
 * @file Task.h
 * @brief Definice třídy Task a výčtového typu TaskType
 * @author Filip Heider
 * @date 2025-05-10
 */

 /**
  * @brief Typy úloh
  *
  * Tento výčtový typ definuje možné druhy výpočetních úloh podle jejich náročnosti.
  */
enum class TaskType
{
    HIGH,    ///< Náročná úloha (H)
    MEDIUM,  ///< Středně náročná úloha (M)
    LOW      ///< Nenáročná úloha (L)
};

/**
 * @brief Třída reprezentující výpočetní úlohu
 *
 * Tato třída zapouzdřuje výpočetní úlohu s definovanou náročností (typem).
 * Úloha je základní jednotkou pro plánování v simulátoru procesoru.
 */
class Task
{
private:
    TaskType type;  ///< Typ úlohy definující její náročnost

public:
    /**
     * @brief Konstruktor úlohy
     * @param t Typ úlohy určující její náročnost
     */
    Task(TaskType t);

    /**
     * @brief Získá typ úlohy
     * @return Typ úlohy (HIGH, MEDIUM nebo LOW)
     */
    TaskType getType() const;
};