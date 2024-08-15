#ifndef IBOOKINGSTRATEGY_H
#define IBOOKINGSTRATEGY_H

#include "User.h"
#include "FitnessClass.h"
#include "ClassType.h"

class IBookingStrategy {
public:
    virtual bool book(User& user, FitnessClass& fitnessClass) = 0;
    virtual ~IBookingStrategy() = default;
};

#endif // IBOOKINGSTRATEGY_H
