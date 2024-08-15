#ifndef IAUTHENTICATABLE_H
#define IAUTHENTICATABLE_H

#include <string>

class IAuthenticatable {
public:
    virtual bool login(std::string password) const = 0;
    virtual ~IAuthenticatable() = default;
};

#endif // IAUTHENTICATABLE_H
