/**
 * @file Task.cpp
 * @brief Implementace třídy Task
 * @author Filip Heider
 * @date 2025-05-10
 */

#include "Task.h"

 /**
  * @brief Konstruktor úlohy
  *
  * Inicializuje úlohu zadaného typu.
  *
  * @param t Typ úlohy určující její náročnost
  */
Task::Task(TaskType t) : type(t)
{
}

/**
 * @brief Získá typ úlohy
 * @return Typ úlohy (HIGH, MEDIUM nebo LOW)
 */
TaskType Task::getType() const
{
    return type;
}