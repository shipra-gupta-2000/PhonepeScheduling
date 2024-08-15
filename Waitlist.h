#ifndef WAITLIST_H
#define WAITLIST_H

#include "User.h"
#include <unordered_map>
#include <queue>
#include <mutex>
#include <iostream>
#include "ClassType.h"

class Waitlist {
public:
    static Waitlist& getInstance() {
        static Waitlist instance;
        return instance;
    }

    void enqueue(User& user, ClassType className);
    User* dequeue(ClassType className);

private:
    Waitlist() = default;
    Waitlist(const Waitlist&) = delete;
    Waitlist& operator=(const Waitlist&) = delete;

    std::unordered_map<ClassType, std::queue<User*>> waitlist;
    std::mutex mtx;
};

#endif // WAITLIST_H
