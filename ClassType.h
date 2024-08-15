// ClassType.h
#ifndef CLASSTYPE_H
#define CLASSTYPE_H

#include <string>

enum class ClassType {
    Yoga,
    Gym,
    Dance,
    // Add other class types as needed
};

std::string getName(ClassType type);

#endif // CLASSTYPE_H