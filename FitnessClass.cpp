#include "FitnessClass.h"
#include <iostream>
#include "ClassType.h"

FitnessClass::FitnessClass(ClassType type, int capacity, const std::chrono::system_clock::time_point& time)
    : type(type), capacity(capacity), bookedCount(0), time(time) {
    if (capacity <= 0) {
        throw std::invalid_argument("Class capacity must be greater than zero.");
    }
}

bool FitnessClass::isFull() const { return bookedCount >= capacity; }

bool FitnessClass::book() {
    if (isFull()) {
        std::cerr << "Error: Class is full. Cannot book." << std::endl;
        return false;
    }
    bookedCount++;
    std::cout << "Booked a spot in class." << std::endl;
    return true;
}

void FitnessClass::cancel() {
    if (bookedCount > 0) {
        bookedCount--;
        std::cout << "Canceled a spot in class." << std::endl;
    } else {
        std::cerr << "Error: No bookings to cancel in class." << std::endl;
    }
}

ClassType FitnessClass::getClassType() const { return type; }

std::chrono::system_clock::time_point FitnessClass::getTime() const { return time; }
