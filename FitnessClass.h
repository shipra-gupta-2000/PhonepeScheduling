
#ifndef FITNESSCLASS_H
#define FITNESSCLASS_H

#include <string>
#include <chrono>
#include <stdexcept>
#include "ClassType.h"


class FitnessClass {
public:
    FitnessClass(ClassType type, int capacity, const std::chrono::system_clock::time_point& time);

    bool isFull() const;
    bool book();
    void cancel();
    ClassType getClassType() const;
    std::chrono::system_clock::time_point getTime() const;

private:
    ClassType type;
    int capacity;
    int bookedCount;
    std::chrono::system_clock::time_point time;
};

#endif // FITNESSCLASS_H
