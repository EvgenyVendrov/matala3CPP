#include "PhysicalNumber.h"
#include "Unit.h"
using ariel::PhysicalNumber, ariel::Unit;

////////////////////PUBLIC////////////////////

//constuctor
PhysicalNumber::PhysicalNumber(double value, Unit type)
{
    this->_value = value;
    this->_type = type;
}

////////////////////operators////////////////////

//arithmetic + operators:
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &arg2) const
{
    return arg2;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &arg2)
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

PhysicalNumber &PhysicalNumber::operator+()
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

//arithmetic - operators:
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &arg2) const
{
    return arg2;
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &arg2)
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

PhysicalNumber &PhysicalNumber::operator-()
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

//comparison operators:
bool PhysicalNumber::operator<(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator==(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber &arg2) const
{
    return false;
}

//increment / decrement operators:
PhysicalNumber &PhysicalNumber::operator++(const int dummyArgForPostfix)
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

PhysicalNumber &PhysicalNumber::operator++()
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

PhysicalNumber &PhysicalNumber::operator--(const int dummyArgForPostfix)
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

PhysicalNumber &PhysicalNumber::operator--()
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

//friend I/O operators:
std::ostream &ariel::operator<<(std::ostream &os, const PhysicalNumber &arg)
{
    os << arg._value << "["<<"]";
    return os;
}
std::istream &ariel::operator>>(std::istream &is, PhysicalNumber &arg)
{
   std::string helpingS;
   is >> helpingS;
   arg._value=0;
   arg._type = Unit::G;
   return is;
}
