#include "task.h"

Task::Task(TaskType t) : type(t) {
}

TaskType Task::getType() const {
    return type;
}