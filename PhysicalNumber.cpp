#include "PhysicalNumber.h"
#include "Unit.h"
#include <string.h>
#include <sstream>
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
    if (!this->canWeCalcBoth(arg2))
    {
        throw "YOU CAN NOT USE THIS OPERATOR ON TWO INCOMPATIBLE DIMENSIONS";
    }
    double valueFirst = this->conv2min();
    double valueSecond = arg2.conv2min();
    Unit toBeMade = this->getUnit();
    double result = normalizeResult(valueFirst - valueSecond, toBeMade);
    PhysicalNumber output(result, toBeMade);
    return output;
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &arg2)
{
    PhysicalNumber p(0, Unit::CM);
    return p;
}

//unary -
PhysicalNumber &PhysicalNumber::operator-()
{
    double value = this->getValue();
    value *= (-1);
    PhysicalNumber output(value, this->getUnit());
    return output;
}

//comparison operators:
bool PhysicalNumber::operator<(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &arg2) const
{
    if (!this->canWeCalcBoth(arg2))
    {
        throw "YOU CAN NOT USE THIS OPERATOR ON TWO INCOMPATIBLE DIMENSIONS";
    }
    double valueFirst = this->conv2min();
    double valueSecond = arg2.conv2min();
    if (valueFirst <= valueSecond)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber &arg2) const
{
    if (!this->canWeCalcBoth(arg2))
    {
        throw "YOU CAN NOT USE THIS OPERATOR ON TWO INCOMPATIBLE DIMENSIONS";
    }
    double valueFirst = this->conv2min();
    double valueSecond = arg2.conv2min();
    if (valueFirst > valueSecond)
    {
        return true;
    }
    return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &arg2) const
{
    return false;
}

bool PhysicalNumber::operator==(const PhysicalNumber &arg2) const
{
    if (!this->canWeCalcBoth(arg2))
    {
        throw "YOU CAN NOT USE THIS OPERATOR ON TWO INCOMPATIBLE DIMENSIONS";
    }
    double valueFirst = this->conv2min();
    double valueSecond = arg2.conv2min();
    if (valueFirst == valueSecond)
    {
        return true;
    }
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

    string saver;
    is >> saver;
    Unit unit;
    double value;
    unit = PhysicalNumber::getUnitFromString(saver);
    value = PhysicalNumber::retVal(saver);
    arg.setUnit(unit);
    arg.setValue(value);
    return is;
}

////////////////////getters////////////////////

Unit PhysicalNumber::getUnit() const
{
    return this->_type;
}

double PhysicalNumber::getValue() const
{
    return this->_value;
}

////////////////////PRIVATE////////////////////
std::string PhysicalNumber::getUnitInString() const
{
    Unit helpingVar = this->getUnit();
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

Unit PhysicalNumber::getUnitFromString(string str)
{
    string unit;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
        {
            i++;
            while (str[i] != ']')
            {
                unit += str[i];
                i++;
            }
        }
    }
    if (unit.compare("g") == 0)
    {
        return Unit::G;
    }
    else if (unit.compare("kg") == 0)
    {
        return Unit::KG;
    }
    else if (unit.compare("ton") == 0)
    {
        return Unit::TON;
    }
    else if (unit.compare("cm") == 0)
    {
        return Unit::CM;
    }
    else if (unit.compare("m") == 0)
    {
        return Unit::M;
    }
    else if (unit.compare("km") == 0)
    {
        return Unit::KM;
    }
    else if (unit.compare("sec") == 0)
    {
        return Unit::SEC;
    }
    else if (unit.compare("min") == 0)
    {
        return Unit::MIN;
    }
    else if (unit.compare("hour") == 0)
    {
        return Unit::HOUR;
    }
}

double PhysicalNumber::retVal(string str)
{
    string helpingS;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
        {
            i += str.length();
        }
        else
        {
            helpingS += str[i];
        }
    }
    std::stringstream helpingStream(helpingS);
    double output;
    helpingStream >> output;
    std::cout<<output<<std::endl;
    return output;
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
    Unit helpingVar = this->getUnit();
    switch (helpingVar)
    {
    case Unit::G:
        return (this->getValue());
    case Unit::KG:
        return (this->getValue()) * 1000;
    case Unit::TON:
        return (this->getValue()) * 1000 * 1000;
    case Unit::CM:
        return (this->getValue());
    case Unit::M:
        return (this->getValue()) * 100;
    case Unit::KM:
        return (this->getValue()) * 100 * 1000;
    case Unit::SEC:
        return (this->getValue());
    case Unit::MIN:
        return (this->getValue()) * 60;
    case Unit::HOUR:
        return (this->getValue()) * 60 * 60;
    default:
        break;
    }
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

void PhysicalNumber::setValue(const double value)
{
    this->_value = value;
}

void PhysicalNumber::setUnit(const Unit type)
{
    this->_type = type;
}
