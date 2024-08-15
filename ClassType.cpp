// ClassType.cpp
#include "ClassType.h"

std::string getName(ClassType type) {
    switch (type) {
        case ClassType::Yoga:
            return "Yoga";
        case ClassType::Gym:
            return "Gym";
        case ClassType::Dance:
            return "Dance";
        // Handle other class types as needed
        default:
            return "Unknown";
    }
}