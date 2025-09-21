#include "scheduler.h"
#include <fstream>
#include <iostream>

using namespace std;

Scheduler::Scheduler() :
    highCore(CoreType::HIGH),
    mediumCore(CoreType::MEDIUM),
    lowCore(CoreType::LOW) {}

bool Scheduler::loadTasks(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Chyba: Nelze otevøít soubor " << filename << endl;
        return false;
    }

    int taskCount;
    file >> taskCount;

    if (file.fail()) 
    {
        cerr << "Chyba pøi ètení poètu úloh!" << endl;
        return false;
    }

    tasks.clear();
    tasks.reserve(taskCount);

    char taskChar;
    int loadedTasks = 0;

    while (loadedTasks < taskCount && file >> taskChar) 
    {
        TaskType taskType;
        switch (taskChar) {
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

void Scheduler::resetCores()
{
    // Reset jader pro novou dávku
    highCore = Core(CoreType::HIGH);
    mediumCore = Core(CoreType::MEDIUM);
    lowCore = Core(CoreType::LOW);
}

void Scheduler::distributeRoundRobin(size_t batchStart) 
{
    size_t remainingTasks = (tasks.size() - batchStart < 8) ? (tasks.size() - batchStart) : 8;

    for (size_t i = 0; i < remainingTasks; ++i) 
    {
        TaskType taskType = tasks[batchStart + i];

        // Round-robin distribuce (0 = high, 1 = medium, 2 = low)
        switch (i % 3) 
        {
        case 0: highCore.addTask(taskType); break;
        case 1: mediumCore.addTask(taskType); break;
        case 2: lowCore.addTask(taskType); break;
        }
    }
}
void Scheduler::distributeOptimized(size_t batchStart)
{
    size_t remainingTasks = (tasks.size() - batchStart < 8) ? (tasks.size() - batchStart) : 8;

    if (remainingTasks == 0)
    {
        return;
    }

    // Pøiøazení úloh ideálním jádrùm s ohledem na vytížení
    for (size_t i = 0; i < remainingTasks; i++) 
    {
        TaskType taskType = tasks[batchStart + i];

        // Dynamické rozdìlení úloh podle vytížení
        if (taskType == TaskType::HIGH) 
        {
            if (highCore.getQueueSize() > mediumCore.getQueueSize() + 3) 
            {
                mediumCore.addTask(taskType);
            }
            else if (highCore.getQueueSize() > lowCore.getQueueSize() + 3) 
            {
                lowCore.addTask(taskType);
            }
            else {
                highCore.addTask(taskType);
            }
        }
        else if (taskType == TaskType::MEDIUM) 
        {
            if (mediumCore.getQueueSize() > lowCore.getQueueSize() + 3) 
            {
                lowCore.addTask(taskType);
            }
            else if (mediumCore.getQueueSize() > highCore.getQueueSize() + 3) 
            {
                highCore.addTask(taskType);
            }
            else 
            {
                mediumCore.addTask(taskType);
            }
        }
        else if (taskType == TaskType::LOW) 
        {
            if (lowCore.getQueueSize() > mediumCore.getQueueSize() + 3) 
            {
                mediumCore.addTask(taskType);
            }
            else if (lowCore.getQueueSize() > highCore.getQueueSize() + 3) 
            {
                highCore.addTask(taskType);
            }
            else 
            {
                lowCore.addTask(taskType);
            }
        }
    }
}


int Scheduler::processBatch(size_t batchStart, void (Scheduler::* distributionStrategy)(size_t)) {
    resetCores();

    (this->*distributionStrategy)(batchStart);

    int timeUnits = 0;
    bool allIdle = false;

    while (!allIdle) {
        timeUnits++;

        highCore.processTimeUnit();
        mediumCore.processTimeUnit();
        lowCore.processTimeUnit();

        allIdle = highCore.isIdle() && mediumCore.isIdle() && lowCore.isIdle();

        if (timeUnits > 100) {
            break;
        }
    }

    return timeUnits;
}

int Scheduler::simulateRoundRobin() {
    int totalTime = 0;
    size_t batchSize = 8;

    for (size_t i = 0; i < tasks.size(); i += batchSize) {
        totalTime += processBatch(i, &Scheduler::distributeRoundRobin);
    }

    return totalTime;
}

int Scheduler::simulateOptimized() {
    int totalTime = 0;
    size_t batchSize = 8;

    for (size_t i = 0; i < tasks.size(); i += batchSize) {
        totalTime += processBatch(i, &Scheduler::distributeOptimized);
    }

    return totalTime;
}

