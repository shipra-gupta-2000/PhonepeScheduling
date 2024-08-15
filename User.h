#ifndef USER_H
#define USER_H

#include "IAuthenticatable.h"
#include "IBookable.h"
#include <string>
#include <stdexcept>
#include "ClassType.h"

enum class UserTier { Platinum, Gold, Silver };

class User : public IAuthenticatable, public IBookable {
public:
    User(const std::string& name, const std::string& password, UserTier tier);
    virtual ~User() = default;

    std::string getName() const;
    bool login(std::string password) const ;
    bool canBook() const override;
    void incrementBooking() override;
    void decrementBooking() override;

    virtual int getMaxBookings() const;

protected:
    std::string name;
    std::string password;
    UserTier userTier;
    int bookedClasses;
};

class Admin : public User {
public:
    Admin(const std::string& name, const std::string& password);
    void createClass(ClassType className, int capacity);
    void cancelClass(ClassType className);
};

#endif // USER_H
