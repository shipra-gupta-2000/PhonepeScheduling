#include "User.h"
#include <iostream>
#include "ClassType.h"
#include <string.h>

User::User(const std::string& name, const std::string& password, UserTier tier)
    : name(name), password(password), userTier(tier), bookedClasses(0) {}

std::string User::getName() const { return name; }

bool User::login(std::string password) const { return this->password == password; }

bool User::canBook() const {
    if (bookedClasses >= getMaxBookings()) {
        std::cerr << "Error: Booking limit reached for user: " << name << std::endl;
        return false;
    }
    return true;
}

void User::incrementBooking() {
    if (!canBook()) {
        throw std::runtime_error("Cannot increment booking: limit reached.");
    }
    bookedClasses++;
}

void User::decrementBooking() {
    if (bookedClasses > 0) {
        bookedClasses--;
    } else {
        std::cerr << "Error: No bookings to cancel for user: " << name << std::endl;
    }
}

int User::getMaxBookings() const {
    switch (userTier) {
        case UserTier::Platinum: return 10;
        case UserTier::Gold: return 5;
        case UserTier::Silver: return 3;
        default: throw std::runtime_error("Unknown user tier.");
    }
}

Admin::Admin(const std::string& name, const std::string& password)
    : User(name, password, UserTier::Platinum) {}

void Admin::createClass(ClassType className, int capacity) {
    std::cout << "Admin creating class: " << ::getName(className) << " with capacity: " << capacity << std::endl;
}

void Admin::cancelClass(ClassType className) {
    std::cout << "Admin canceling class: " << ::getName(className) << std::endl;
}
