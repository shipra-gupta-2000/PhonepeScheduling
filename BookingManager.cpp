#include "BookingManager.h"
#include "ClassType.h"

DefaultBookingStrategy BookingManager::defaultStrategy;

bool BookingManager::bookClass(User& user, ClassType className) {
    std::lock_guard<std::mutex> lock(mtx);
    FitnessClass* fitnessClass = classManager.getClass(ClassType::Yoga);  // Adjust as needed for ClassType
    if (!fitnessClass) {
        std::cout << "Error: Class " << ::getName(className) << " not found." << std::endl;
        return false;
    }

    if (!user.canBook()) {
        std::cerr << "Error: User " << user.getName() << " has reached the booking limit." << std::endl;
        return false;
    }

    if (!strategy->book(user, *fitnessClass)) {
        waitlist.enqueue(user, className);
        return false;
    }

    return true;
}

void BookingManager::cancelBooking(User& user, ClassType className) {
    std::lock_guard<std::mutex> lock(mtx);
    FitnessClass* fitnessClass = classManager.getClass(className);  // Adjust as needed for ClassType
    if (!fitnessClass) {
        std::cerr << "Error: Class " << ::getName(className) << " not found." << std::endl;
        return;
    }

    fitnessClass->cancel();
    user.decrementBooking();

    User* nextUser = waitlist.dequeue(className);
    if (nextUser) {
        bookClass(*nextUser, className);
    }
}
