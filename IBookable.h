#ifndef IBOOKABLE_H
#define IBOOKABLE_H

class IBookable {
public:
    virtual bool canBook() const = 0;
    virtual void incrementBooking() = 0;
    virtual void decrementBooking() = 0;
    virtual ~IBookable() = default;
};

#endif // IBOOKABLE_H
