#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include "FitnessClass.h"
#include <unordered_map>
#include <mutex>
#include "ClassType.h"

class ClassManager {
public:
    static ClassManager& getInstance() {
        static ClassManager instance;
        return instance;
    }

    void addClass(ClassType type, int capacity, const std::chrono::system_clock::time_point& time);
    void cancelClass(ClassType type);
    FitnessClass* getClass(ClassType type);

private:
    ClassManager() = default;
    ClassManager(const ClassManager&) = delete;
    ClassManager& operator=(const ClassManager&) = delete;

    std::unordered_map<ClassType, FitnessClass> classes;
    std::mutex mtx;
};

#endif // CLASSMANAGER_H
