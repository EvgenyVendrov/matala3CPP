#pragma once
#include <string.h>
#include <iostream>

namespace ariel
{
enum class Unit
{
    CM,
    M,
    KM,
    SEC,
    MIN,
    HOUR,
    G,
    KG,
    TON

};
static Unit convString2Unit(const std::string str){
     std::string unit;
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
static std::string convUnit2String(const Unit input){
     switch (input)
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
    }
}
} // namespace ariel
