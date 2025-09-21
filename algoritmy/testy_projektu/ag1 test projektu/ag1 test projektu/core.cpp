#include "core.h"

Core::Core(CoreType t) {
    this->type = t;
    this->currentTaskTime = 0;
    this->processing = false;
}

int Core::getProcessingTime(TaskType taskType) const {
    // Optimální kombinace - 1 jednotka èasu
    if ((type == CoreType::HIGH && taskType == TaskType::HIGH) ||
        (type == CoreType::MEDIUM && taskType == TaskType::MEDIUM) ||
        (type == CoreType::LOW && taskType == TaskType::LOW)) {
        return 1;
    }

    // Neoptimální kombinace - 2 jednotky èasu
    return 2;
}

void Core::startProcessing() {
    if (!queue.empty() && !processing) {
        TaskType taskType = queue.front();
        currentTaskTime = getProcessingTime(taskType);
        processing = true;
    }
}

bool Core::processTimeUnit() {
    // Pokud není co zpracovávat, vrátíme false
    if (queue.empty() && !processing) {
        return false;
    }

    // Inicializace zpracování pokud je potøeba
    startProcessing();

    // Snížení zbývajícího èasu aktuální úlohy
    currentTaskTime--;

    // Pokud je úloha dokonèena
    if (currentTaskTime <= 0) {
        queue.pop();  // Odstraníme dokonèenou úlohu
        processing = false;  // Oznaèíme, že jsme dokonèili zpracování

        // Inicializace zpracování další úlohy, pokud existuje
        startProcessing();

        return true;  // Úloha byla dokonèena
    }

    return false;  // Úloha nebyla dokonèena
}

void Core::addTask(TaskType taskType) {
    queue.push(taskType);

    // Inicializace zpracování pokud je jádro neaktivní
    startProcessing();
}

bool Core::isIdle() const {
    return queue.empty() && !processing;
}

size_t Core::getQueueSize() const {
    return queue.size();
}

CoreType Core::getType() const {
    return type;
}
