#include "User.h"
#include "ClassManager.h"
#include "BookingManager.h"
#include "DefaultBookingStrategy.h"
#include "Waitlist.h"
#include <iostream>
#include <chrono>
#include "ClassType.h"

int main() {
    try {
        // Get instances of Singleton managers
        ClassManager& classManager = ClassManager::getInstance();
        Waitlist& waitlist = Waitlist::getInstance();
        BookingManager& bookingManager = BookingManager::getInstance();

        // Admin creates classes
        Admin admin("admin", "adminpass");
        auto time = std::chrono::system_clock::now() + std::chrono::hours(2);
        classManager.addClass(ClassType::Yoga, 2, time);  // Small class capacity for testing waitlist
        classManager.addClass(ClassType::Gym, 3, time + std::chrono::hours(1));
        classManager.addClass(ClassType::Dance, 1, time + std::chrono::hours(3)); // Only 1 spot

        // Users register
        User user1("Ram", "rampass", UserTier::Gold);
        User user2("Priya", "priyapass", UserTier::Silver);
        User user3("Sonam", "sonampass", UserTier::Platinum);
        User user4("Heena", "heenapass", UserTier::Gold);

        // Test case: Booking classes
        std::cout << "\n=== Test Case: Basic Booking ===\n";
        if (bookingManager.bookClass(user1, ClassType::Yoga)) {
            std::cout << "Ram booked Yoga class.\n";
        } else {
            std::cout << "Ram could not book Yoga class.\n";
        }

        if (bookingManager.bookClass(user2, ClassType::Yoga)) {
            std::cout << "Priya booked Yoga class.\n";
        } else {
            std::cout << "Priya could not book Yoga class.\n";
        }

        // Test case: Booking when class is full (Waitlist)
        std::cout << "\n=== Test Case: Waitlisting ===\n";
        if (bookingManager.bookClass(user3, ClassType::Yoga)) {
            std::cout << "Sonam booked Yoga class.\n";
        } else {
            std::cout << "Sonam was added to the waitlist for Yoga class.\n";
        }

        // Test case: Cancel booking to trigger waitlist
        std::cout << "\n=== Test Case: Cancellation and Waitlist Trigger ===\n";
        bookingManager.cancelBooking(user1, ClassType::Yoga);  // This should allow Sonam to book

        // // Test case: Booking with user at booking limit
        // std::cout << "\n=== Test Case: Booking Limit Reached ===\n";
        // bookingManager.bookClass(user2, "Gym");
        // bookingManager.bookClass(user2, "Dance");  // Priya's tier allows only 3 bookings

        // // This should fail because Priya has reached her booking limit
        // if (bookingManager.bookClass(user2, "Yoga")) {
        //     std::cout << "Priya booked another class (unexpected).\n";
        // } else {
        //     std::cout << "Priya could not book another class (as expected).\n";
        // }

        // // Test case: Booking with higher tier (Platinum)
        // std::cout << "\n=== Test Case: Platinum User Booking ===\n";
        // bookingManager.bookClass(user3, "Gym");
        // bookingManager.bookClass(user3, "Dance");

        // if (bookingManager.bookClass(user3, "Yoga")) {
        //     std::cout << "Sonam was able to book Yoga class.\n";
        // } else {
        //     std::cout << "Sonam could not book Yoga class (unexpected).\n";
        // }

        // // Test case: Cancel all bookings
        // std::cout << "\n=== Test Case: Cancel All Bookings ===\n";
        // bookingManager.cancelBooking(user2, "Gym");
        // bookingManager.cancelBooking(user2, "Dance");

        // if (bookingManager.bookClass(user2, "Yoga")) {
        //     std::cout << "Priya booked Yoga class after cancellations.\n";
        // } else {
        //     std::cout << "Priya could not book Yoga class (unexpected).\n";
        // }

        // // Test case: Booking and Canceling as Admin
        // std::cout << "\n=== Test Case: Admin Booking and Cancellation ===\n";
        // admin.createClass("Pilates", 5);
        // bookingManager.bookClass(admin, "Pilates");

        // bookingManager.cancelBooking(admin, "Pilates");

        // // Test case: Edge case where user tries to cancel non-existing booking
        // std::cout << "\n=== Test Case: Cancel Non-Existing Booking ===\n";
        // bookingManager.cancelBooking(user4, "Gym");  // Heena never booked Gym

        // // Test case: Add users to the waitlist and trigger cancellations
        // std::cout << "\n=== Test Case: Multiple Users on Waitlist ===\n";
        // bookingManager.bookClass(user4, "Dance");  // Heena should be on waitlist (only 1 spot)
        // bookingManager.bookClass(user1, "Dance");  // Ram should also go on waitlist

        // // Canceling Sonam's booking should allow Heena to book Dance
        // bookingManager.cancelBooking(user3, "Dance");

        // // Final state checks
        // std::cout << "\n=== Final State Check ===\n";
        // if (bookingManager.bookClass(user1, "Dance")) {
        //     std::cout << "Ram was able to book Dance class after waitlist was processed.\n";
        // } else {
        //     std::cout << "Ram could not book Dance class (unexpected).\n";
        // }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
