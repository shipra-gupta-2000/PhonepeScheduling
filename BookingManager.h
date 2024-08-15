#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include "ClassManager.h"
#include "Waitlist.h"
#include "IBookingStrategy.h"
#include "DefaultBookingStrategy.h"
#include <mutex>
#include "ClassType.h"

class BookingManager {
public:
    static BookingManager& getInstance() {
        static BookingManager instance(ClassManager::getInstance(), Waitlist::getInstance(), &defaultStrategy);
        return instance;
    }

    bool bookClass(User& user, ClassType className);
    void cancelBooking(User& user, ClassType className);

private:
    BookingManager(ClassManager& classManager, Waitlist& waitlist, IBookingStrategy* strategy)
        : classManager(classManager), waitlist(waitlist), strategy(strategy) {}

    BookingManager(const BookingManager&) = delete;
    BookingManager& operator=(const BookingManager&) = delete;

    ClassManager& classManager;
    Waitlist& waitlist;
    IBookingStrategy* strategy;
    std::mutex mtx;

    static DefaultBookingStrategy defaultStrategy;
};

#endif // BOOKINGMANAGER_H
