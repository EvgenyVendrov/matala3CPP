#include "PhysicalNumber.h"
#include "Unit.h"
#include <string.h>
using ariel::PhysicalNumber, ariel::Unit, std::string;

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
    if (!this->canWeCalcBoth(arg2))
    {
        throw "YOU CAN NOT USE THIS OPERATOR ON TWO INCOMPATIBLE DIMENSIONS";
    }
    double valueFirst = this->conv2min();
    double valueSecond = arg2.conv2min();
    Unit toBeMade = this->getUnit();
    double result = normalizeResult(valueFirst + valueSecond, toBeMade);
    PhysicalNumber output(result, toBeMade);
    return output;
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
    string stringType = arg.getUnitInString();
    os << arg._value << "[" << stringType
       << "]";
    return os;
}
std::istream &ariel::operator>>(std::istream &is, PhysicalNumber &arg)
{
    std::string helpingS;
    is >> helpingS;
    arg._value = 0;
    arg._type = Unit::G;
    return is;
}

//private methods
std::string PhysicalNumber::getUnitInString() const
{
    Unit helpingVar = this->_type;
    switch (helpingVar)
    {
    case Unit::G:
        return "g";
    case Unit::KG:
        return "kg";
    case Unit::TON:
        return "ton";
    case Unit::CM:
        return "cm";
    case Unit::M:
        return "m";
    case Unit::KM:
        return "km";
    case Unit::SEC:
        return "sec";
    case Unit::MIN:
        return "min";
    case Unit::HOUR:
        return "hour";
    default:
        break;
    }
}

bool PhysicalNumber::canWeCalcBoth(const PhysicalNumber &arg) const
{
    Unit TypeOfThis = this->getUnit();
    Unit typeOfArg = arg.getUnit();
    switch (TypeOfThis)
    {
    case Unit::G:
        if (typeOfArg == Unit::G || typeOfArg == Unit::KG || typeOfArg == Unit::TON)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::KG:
        if (typeOfArg == Unit::G || typeOfArg == Unit::KG || typeOfArg == Unit::TON)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::TON:
        if (typeOfArg == Unit::G || typeOfArg == Unit::KG || typeOfArg == Unit::TON)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::CM:
        if (typeOfArg == Unit::CM || typeOfArg == Unit::M || typeOfArg == Unit::KM)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::M:
        if (typeOfArg == Unit::CM || typeOfArg == Unit::M || typeOfArg == Unit::KM)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::KM:
        if (typeOfArg == Unit::CM || typeOfArg == Unit::M || typeOfArg == Unit::KM)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::SEC:
        if (typeOfArg == Unit::SEC || typeOfArg == Unit::MIN || typeOfArg == Unit::HOUR)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::MIN:
        if (typeOfArg == Unit::SEC || typeOfArg == Unit::MIN || typeOfArg == Unit::HOUR)
        {
            return true;
        }
        else
        {
            return false;
        };
    case Unit::HOUR:
        if (typeOfArg == Unit::SEC || typeOfArg == Unit::MIN || typeOfArg == Unit::HOUR)
        {
            return true;
        }
        else
        {
            return false;
        };
    default:
        break;
    }
}

double PhysicalNumber::conv2min() const
{
    Unit helpingVar = this->_type;
    switch (helpingVar)
    {
    case Unit::G:
        return (this->_value);
    case Unit::KG:
        return (this->_value) * 1000;
    case Unit::TON:
        return (this->_value) * 1000 * 1000;
    case Unit::CM:
        return (this->_value);
    case Unit::M:
        return (this->_value) * 100;
    case Unit::KM:
        return (this->_value) * 100 * 1000;
    case Unit::SEC:
        return (this->_value);
    case Unit::MIN:
        return (this->_value) * 60;
    case Unit::HOUR:
        return (this->_value) * 60 * 60;
    default:
        break;
    }
}

Unit PhysicalNumber::getUnit() const
{
    return this->_type;
}

double PhysicalNumber::normalizeResult(const double result, Unit type)
{
    switch (type)
    {
    case Unit::G:
        return result;
    case Unit::KG:
        return result / 1000;
    case Unit::TON:
        return result / (1000 * 1000);
    case Unit::CM:
        return result;
    case Unit::M:
        return result / 100;
    case Unit::KM:
        return result / (100 * 1000);
    case Unit::SEC:
        return result;
    case Unit::MIN:
        return result / 60;
    case Unit::HOUR:
        return result / (60 * 60);
    default:
        break;
    }
}