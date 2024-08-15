#include "ClassManager.h"
#include <iostream>
#include "ClassType.h"

void ClassManager::addClass(ClassType type, int capacity, const std::chrono::system_clock::time_point& time) {
    std::lock_guard<std::mutex> lock(mtx);
    if (classes.find(type) != classes.end()) {
        std::cerr << "Error: Class already exists." << std::endl;
        return;
    }
    classes.emplace(type, FitnessClass(type, capacity, time));
    std::cout << "Class added with capacity: " << capacity << std::endl;
}

void ClassManager::cancelClass(ClassType type) {
    std::lock_guard<std::mutex> lock(mtx);
    if (classes.erase(type)) {
        std::cout << "Class canceled." << std::endl;
    } else {
        std::cerr << "Error: Class not found." << std::endl;
    }
}

FitnessClass* ClassManager::getClass(ClassType type) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = classes.find(type);
    if (it != classes.end()) {
        return &it->second;
    }
    return nullptr;
}
