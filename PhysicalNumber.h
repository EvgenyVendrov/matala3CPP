#pragma once
#include "Unit.h"
#include <iostream>

namespace ariel
{
class PhysicalNumber
{
private:
    double _value;
    Unit _type;
    void setValue(const double value);
    void setType(const double value);


public:
    //constructor & distructor
    PhysicalNumber(double value, Unit type);
    //arithmetic + operators:
    PhysicalNumber operator+(const PhysicalNumber &arg2) const;
    PhysicalNumber &operator+=(const PhysicalNumber &arg2);
    PhysicalNumber &operator+();

    //arithmetic - operators:
    PhysicalNumber operator-(const PhysicalNumber &arg2) const;
    PhysicalNumber &operator-=(const PhysicalNumber &arg2);
    PhysicalNumber &operator-();

    //comparison operators:
    bool operator>(const PhysicalNumber &arg2) const;
    bool operator>=(const PhysicalNumber &arg2) const;
    bool operator<(const PhysicalNumber &arg2) const;
    bool operator<=(const PhysicalNumber &arg2) const;
    bool operator==(const PhysicalNumber &arg2) const;
    bool operator!=(const PhysicalNumber &arg2) const;

    //increment / decrement operators:
    PhysicalNumber &operator++(const int dummyArgForPostfix);
    PhysicalNumber &operator++();
    PhysicalNumber &operator--(const int dummyArgForPostfix);
    PhysicalNumber &operator--();

    //friend I/O operators:
    friend std::ostream &operator<<(std::ostream &os, const PhysicalNumber &arg);
    friend std::istream &operator>>(std::istream &is,  PhysicalNumber &arg);
};

} // namespace ariel