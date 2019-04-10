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
    std::string getUnitInString() const;
    static Unit getUnitFromString(std::string str);
    static double retVal(std::string str);
    bool canWeCalcBoth(const PhysicalNumber &arg) const;
    double conv2min() const;
    static double normalizeResult(const double result, const Unit type);
    void setUnit (const Unit type);
    void setValue (const double value);
    static Unit getUnitOfString (std::string str);
    static bool isFormatCorrect (std::string str, PhysicalNumber &arg); 
    static void throwExe(std::string type1,std::string type2);


  public:
    //constructor 
    PhysicalNumber(double value, Unit type);
    Unit getUnit() const;
    double getValue() const;
    //arithmetic + operators:
    PhysicalNumber operator+(const PhysicalNumber &arg2) const;
    PhysicalNumber &operator+=(const PhysicalNumber &arg2);
    PhysicalNumber &operator+() const;

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
    friend std::istream &operator>>(std::istream &is, PhysicalNumber &arg);
};

} // namespace ariel