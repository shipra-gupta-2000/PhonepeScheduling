#ifndef DEFAULTBOOKINGSTRATEGY_H
#define DEFAULTBOOKINGSTRATEGY_H

#include "IBookingStrategy.h"
#include "ClassType.h"

class DefaultBookingStrategy : public IBookingStrategy {
public:
    bool book(User& user, FitnessClass& fitnessClass) override {
        if (fitnessClass.isFull()) {
            return false;
        }
        fitnessClass.book();
        user.incrementBooking();
        return true;
    }
};

#endif // DEFAULTBOOKINGSTRATEGY_H
