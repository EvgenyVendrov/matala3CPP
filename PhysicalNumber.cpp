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
//distructor
PhysicalNumber::~PhysicalNumber()
{
}

////////////////////operators////////////////////

//arithmetic + operators:
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &arg2) const
{
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &arg2)
{
}

PhysicalNumber &PhysicalNumber::operator+()
{
}

//arithmetic - operators:
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &arg2) const
{
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &arg2)
{
}

PhysicalNumber &PhysicalNumber::operator-()
{
}

//comparison operators:
bool PhysicalNumber::operator<(const PhysicalNumber &arg2) const
{
}

bool PhysicalNumber::operator<=(const PhysicalNumber &arg2) const
{
}

bool PhysicalNumber::operator>(const PhysicalNumber &arg2) const
{
}

bool PhysicalNumber::operator>=(const PhysicalNumber &arg2) const
{
}

bool PhysicalNumber::operator==(const PhysicalNumber &arg2) const
{
}

bool PhysicalNumber::operator!=(const PhysicalNumber &arg2) const
{
}

//increment / decrement operators:
PhysicalNumber &PhysicalNumber::operator++(const int dummyArgForPostfix)
{
}

PhysicalNumber &PhysicalNumber::operator++()
{
}

PhysicalNumber &PhysicalNumber::operator--(const int dummyArgForPostfix)
{
}

PhysicalNumber &PhysicalNumber::operator--()
{
}

//friend I/O operators:
std::ostream &ariel::operator<<(std::ostream &os, const PhysicalNumber &arg)
{
}
std::istream &ariel::operator>>(std::istream &is, const PhysicalNumber &arg)
{
}
