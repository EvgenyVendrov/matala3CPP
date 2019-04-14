#pragma once
#include "Unit.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdexcept>
#include <cmath>

namespace ariel
{
class PhysicalNumber
{
private:
  //class members
  double _value;
  Unit _type;

  // private supporting methods
  bool canWeCalcBoth(const PhysicalNumber &arg) const;
  double convVal2min() const;

  //static supproting methods
  static double parseValue(std::string str);
  static double normalizeResult(const double result, const Unit type);
  static bool isFormatCorrect(std::string str, PhysicalNumber &arg);
  static void throwExe(std::string type1, std::string type2);

  //setters
  void setUnit(const Unit type);
  void setValue(const double value);

  //2 move 2 unit
  std::string getUnitInString() const;

public:
  //constructor
  PhysicalNumber(double value, Unit type);

  //getters
  Unit getUnit() const;
  double getValue() const;

  //arithmetic + operators:
  PhysicalNumber operator+(const PhysicalNumber &arg2) const;
  PhysicalNumber &operator+=(const PhysicalNumber &arg2);
  PhysicalNumber operator+();

  //arithmetic - operators:
  PhysicalNumber operator-(const PhysicalNumber &arg2) const;
  PhysicalNumber &operator-=(const PhysicalNumber &arg2);
  PhysicalNumber operator-();

  //comparison operators:
  bool operator>(const PhysicalNumber &arg2) const;
  bool operator>=(const PhysicalNumber &arg2) const;
  bool operator<(const PhysicalNumber &arg2) const;
  bool operator<=(const PhysicalNumber &arg2) const;
  bool operator==(const PhysicalNumber &arg2) const;
  bool operator!=(const PhysicalNumber &arg2) const;

  //increment / decrement operators:
  PhysicalNumber operator++(const int dummyArgForPostfix);
  PhysicalNumber &operator++();
  PhysicalNumber operator--(const int dummyArgForPostfix);
  PhysicalNumber &operator--();

  //friend I/O operators:
  friend std::ostream &operator<<(std::ostream &os, const PhysicalNumber &arg);
  friend std::istream &operator>>(std::istream &is, PhysicalNumber &arg);
};

} // namespace ariel