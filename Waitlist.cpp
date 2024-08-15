#include "Waitlist.h"
#include "ClassType.h"

void Waitlist::enqueue(User& user, ClassType className) {
    std::lock_guard<std::mutex> lock(mtx);
    waitlist[className].push(&user);
    std::cout << "User " << user.getName() << " added to waitlist for class: " << ::getName(className) << std::endl;
}

User* Waitlist::dequeue(ClassType className) {
    std::lock_guard<std::mutex> lock(mtx);
    if (waitlist[className].empty()) {
        std::cerr << "No users in waitlist for class: " << ::getName(className) << std::endl;
        return nullptr;
    }

    User* user = waitlist[className].front();
    waitlist[className].pop();
    std::cout << "User " << user->getName() << " removed from waitlist for class: " <<::getName(className) << std::endl;
    return user;
}
