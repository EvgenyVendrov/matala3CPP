/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main()
{
  badkan::TestCase testcase;
  int grade = 0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0)
  {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    testcase
        .setname("Basic output")
        .CHECK_OUTPUT(a, "2[km]")
        .CHECK_OUTPUT(b, "300[m]")

        .setname("Compatible dimensions")
        .CHECK_OUTPUT(b + a, "2300[m]")
        .CHECK_OUTPUT((a += b), "2.3[km]")
        .CHECK_OUTPUT(a, "2.3[km]")
        .CHECK_OUTPUT(a + a, "4.6[km]")
        .CHECK_OUTPUT(b - b, "0[m]")
        .CHECK_OUTPUT(c, "2[hour]")
        .CHECK_OUTPUT(d, "30[min]")
        .CHECK_OUTPUT(d + c, "150[min]")

        .setname("Incompatible dimensions")
        .CHECK_THROWS(a + c)
        .CHECK_THROWS(a + d)
        .CHECK_THROWS(b + c)
        .CHECK_THROWS(b + d)

        .setname("Basic input")
        .CHECK_OK(istringstream("700[kg]") >> a)
        .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]");

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

    // sanity test's - just cheking that all features are basicly valid:
    // init the to be tested physical numbers
    PhysicalNumber gram(5, Unit::G);
    PhysicalNumber kilogram(6, Unit::KG);
    PhysicalNumber ton(0.7, Unit::TON);
    PhysicalNumber centimeter(-8, Unit::CM);
    PhysicalNumber meter(9, Unit::M);
    PhysicalNumber kilometer(3, Unit::KM);
    PhysicalNumber second(11, Unit::SEC);
    PhysicalNumber minute(-12, Unit::MIN);
    PhysicalNumber hour(0.5, Unit::HOUR);
    // 1. every unit-type tested with unit-types which should work - with every operator
    // arithmetic testing:
    testcase
        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sanity test = > arithmetic (+) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(gram + gram, "10[g]")
        .CHECK_OUTPUT(gram + kilogram, "6005[g]")
        .CHECK_OUTPUT(gram + ton, "700005[g]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(kilogram + kilogram, "12[kg]")
        .CHECK_OUTPUT(kilogram + gram, "6.005[kg]")
        .CHECK_OUTPUT(kilogram + ton, "706[kg]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(ton + ton, "1.4[ton]")
        .CHECK_OUTPUT(ton + gram, "0.700005[ton]")
        .CHECK_OUTPUT(ton + kilogram, "0.706[ton]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(gram - gram, "0[g]")
        .CHECK_OUTPUT(gram - kilogram, "-5995[g]")
        .CHECK_OUTPUT(gram - ton, "-699995[g]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT(kilogram - kilogram, "0[kg]")
        .CHECK_OUTPUT(kilogram - gram, "5.995[kg]")
        .CHECK_OUTPUT(kilogram - ton, "-694[kg]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(ton - ton, "0[ton]")
        .CHECK_OUTPUT(ton - gram, "0.699995[ton]")
        .CHECK_OUTPUT(ton - kilogram, "0.694[ton]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (+=) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram += gram), "10[g]")
        .CHECK_OUTPUT((gram += kilogram), "6010[g]")
        .CHECK_OUTPUT((gram += ton), "706010[g]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram += kilogram), "12[kg]")
        .CHECK_OUTPUT((kilogram += gram), "718.01[kg]")
        .CHECK_OUTPUT((kilogram += ton), "1418.01[kg]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton += ton), "1.4[ton]")
        .CHECK_OUTPUT((ton += gram), "2.10601[ton]")
        .CHECK_OUTPUT((ton += kilogram), "3.52402[ton]");
    ////////////////////////////////////////////////
    //init the variables agian as we used "="
    gram = PhysicalNumber(5, Unit::G);
    kilogram = PhysicalNumber(6, Unit::KG);
    ton = PhysicalNumber(0.7, Unit::TON);
    testcase
        ////////////////////////////////////////////
        //.setname("sanity test = > unary (+) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(+gram, "5[g]")
        .CHECK_OUTPUT(+kilogram, "6[kg]")
        .CHECK_OUTPUT((+ton), "0.7[ton]")
        //   /////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-=) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram -= gram), "0[g]")
        .CHECK_OUTPUT((gram -= kilogram), "-6000[g]")
        .CHECK_OUTPUT((gram -= ton), "-706000[g]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram -= kilogram), "0[kg]")
        .CHECK_OUTPUT((kilogram -= gram), "706[kg]")
        .CHECK_OUTPUT((kilogram -= ton), "6[kg]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton -= ton), "0[ton]")
        .CHECK_OUTPUT((ton -= gram), "0.706[ton]")
        .CHECK_OUTPUT((ton -= kilogram), "0.7[ton]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > unary (-) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-gram, "706000[g]")
        .CHECK_OUTPUT(-kilogram, "-6[kg]")
        .CHECK_OUTPUT(-ton, "-0.7[ton]")
        //   //////////////////////////////////////////////

        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sanity test = > arithmetic (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(centimeter + centimeter, "-16[cm]")
        .CHECK_OUTPUT(centimeter + meter, "892[cm]")
        .CHECK_OUTPUT(centimeter + kilometer, "299992[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(meter + meter, "18[m]")
        .CHECK_OUTPUT(meter + centimeter, "8.92[m]")
        .CHECK_OUTPUT(meter + kilometer, "3009[m]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(kilometer + kilometer, "6[km]")
        .CHECK_OUTPUT(kilometer + centimeter, "2.99992[km]")
        .CHECK_OUTPUT(kilometer + meter, "3.009[km]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(centimeter - centimeter, "0[cm]")
        .CHECK_OUTPUT(centimeter - meter, "-908[cm]")
        .CHECK_OUTPUT(centimeter - kilometer, "-300008[cm]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT(meter - meter, "0[m]")
        .CHECK_OUTPUT(meter - centimeter, "9.08[m]")
        .CHECK_OUTPUT(meter - kilometer, "-2991[m]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(kilometer - kilometer, "0[km]")
        .CHECK_OUTPUT(kilometer - centimeter, "3.00008[km]")
        .CHECK_OUTPUT(kilometer - meter, "2.991[km]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (+=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter += centimeter), "-16[cm]")
        .CHECK_OUTPUT((centimeter += meter), "884[cm]")
        .CHECK_OUTPUT((centimeter += kilometer), "300884[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter += meter), "18[m]")
        .CHECK_OUTPUT((meter += centimeter), "3026.84[m]")
        .CHECK_OUTPUT((meter += kilometer), "6026.84[m]")
        // ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer += kilometer), "6[km]")
        .CHECK_OUTPUT((kilometer += centimeter), "9.00884[km]")
        .CHECK_OUTPUT((kilometer += meter), "15.0357[km]");
    //init vars as we used =
    centimeter = PhysicalNumber(-8, Unit::CM);
    meter = PhysicalNumber(9, Unit::M);
    kilometer = PhysicalNumber(3, Unit::KM);
    testcase
        ////////////////////////////////////////////
        .setname("sanity test = > unary (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(+centimeter, "8[cm]")
        .CHECK_OUTPUT(+meter, "9[m]")
        .CHECK_OUTPUT(+kilometer, "3[km]")
        /////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter -= centimeter), "0[cm]")
        .CHECK_OUTPUT((centimeter -= meter), "-900[cm]")
        .CHECK_OUTPUT((centimeter -= kilometer), "-300900[cm]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((meter -= meter), "0[m]")
        .CHECK_OUTPUT((meter -= centimeter), "3009[m]")
        .CHECK_OUTPUT((meter -= kilometer), "9[m]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer -= kilometer), "0[km]")
        .CHECK_OUTPUT((kilometer -= centimeter), "3.009[km]")
        .CHECK_OUTPUT((kilometer -= meter), "3[km]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > unary (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-centimeter, "300900[cm]")
        .CHECK_OUTPUT(-meter, "-9[m]")
        .CHECK_OUTPUT(-kilometer, "-3[km]")
        //   //////////////////////////////////////////////

        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sanity test = > arithmetic (+) = > should work = > SEC-MIN-HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(second + second, "22[sec]")
        .CHECK_OUTPUT(second + minute, "-709[sec]")
        .CHECK_OUTPUT(second + hour, "1811[sec]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT(minute + minute, "-24[min]")
        .CHECK_OUTPUT(minute + second, "-11.8167[min]")
        .CHECK_OUTPUT(minute + hour, "18[min]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(hour + hour, "1[hour]")
        .CHECK_OUTPUT(hour + second, "0.503056[hour]")
        .CHECK_OUTPUT(hour + minute, "0.3[hour]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-) = > should work = > SEC-MIN-HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(second - second, "0[sec]")
        .CHECK_OUTPUT(second - minute, "731[sec]")
        .CHECK_OUTPUT(second - hour, "-1789[sec]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT(minute - minute, "0[min]")
        .CHECK_OUTPUT(minute - second, "-12.1833[min]")
        .CHECK_OUTPUT(minute - hour, "-42[min]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT(hour - hour, "0[hour]")
        .CHECK_OUTPUT(hour - second, "0.496944[hour]")
        .CHECK_OUTPUT(hour - minute, "0.7[hour]")
        ////////////////////////////////////////////
        .setname("sanity test = > arithmetic (+=) = > should work = > SEC-MIN-HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second += second), "22[sec]")
        .CHECK_OUTPUT((second += minute), "-698[sec]")
        .CHECK_OUTPUT((second += hour), "1102[sec]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute += minute), "-24[min]")
        .CHECK_OUTPUT((minute += second), "-5.63333[min]")
        .CHECK_OUTPUT((minute += hour), "24.3667[min]")
        // ////////////////////////////////////////////
        .CHECK_OUTPUT((hour += hour), "1[hour]")
        .CHECK_OUTPUT((hour += second), "1.30611[hour]")
        .CHECK_OUTPUT((hour += minute), "1.71222[hour]");
    ////////////////////////////////////////////
    second = PhysicalNumber(11, Unit::SEC);
    minute = PhysicalNumber(-12, Unit::MIN);
    hour = PhysicalNumber(0.5, Unit::HOUR);
    testcase
        .setname("sanity test = > unary (+) = > should work = > SEC-MIN-HOUR")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(+second, "11[sec]")
        .CHECK_OUTPUT(+minute, "12[min]")
        .CHECK_OUTPUT(+hour, "0.5[hour]");
    second = PhysicalNumber(11, Unit::SEC);
    minute = PhysicalNumber(-12, Unit::MIN);
    hour = PhysicalNumber(0.5, Unit::HOUR);
    testcase
        //   /////////////////////////////////////////////
        .setname("sanity test = > arithmetic (-=) = > should work = > SEC-MIN-HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second -= second), "0[sec]")
        .CHECK_OUTPUT((second -= minute), "720[sec]")
        .CHECK_OUTPUT((second -= hour), "-1080[sec]")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((minute -= minute), "0[min]")
        .CHECK_OUTPUT((minute -= second), "18[min]")
        .CHECK_OUTPUT((minute -= hour), "-12[min]")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((hour -= hour), "0[hour]")
        .CHECK_OUTPUT((hour -= second), "0.3[hour]")
        .CHECK_OUTPUT((hour -= minute), "0.5[hour]")
        //   ////////////////////////////////////////////
        .setname("sanity test = > unary (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-second, "1080[sec]")
        .CHECK_OUTPUT(-minute, "12[min]")
        .CHECK_OUTPUT(-hour, "-0.5[hour]");
    //   //////////////////////////////////////////////
    gram = PhysicalNumber(10, Unit::G);
    kilogram = PhysicalNumber(0.01, Unit::KG);
    ton = PhysicalNumber(2, Unit::TON);
    centimeter = PhysicalNumber(-8, Unit::CM);
    meter = PhysicalNumber(9, Unit::M);
    kilometer = PhysicalNumber(3, Unit::KM);
    second = PhysicalNumber(11, Unit::SEC);
    minute = PhysicalNumber(-12, Unit::MIN);
    hour = PhysicalNumber(0.5, Unit::HOUR);

    testcase
        //   // comparison testing:

        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sanity test = > comparison (==) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram == gram), "1")
        .CHECK_OUTPUT((gram == kilogram), "1")
        .CHECK_OUTPUT((gram == ton), "0")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram == kilogram), "1")
        .CHECK_OUTPUT((kilogram == gram), "1")
        .CHECK_OUTPUT((kilogram == ton), "0")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton == ton), "1")
        .CHECK_OUTPUT((ton == gram), "0")
        .CHECK_OUTPUT((ton == kilogram), "0")
        //   ////////////////////////////////////////////
        .setname("sanity test = > comparison (!=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram != gram), "0")
        .CHECK_OUTPUT((gram != kilogram), "0")
        .CHECK_OUTPUT((gram != ton), "1")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram != kilogram), "0")
        .CHECK_OUTPUT((kilogram != gram), "0")
        .CHECK_OUTPUT((kilogram != ton), "1")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton != ton), "0")
        .CHECK_OUTPUT((ton != gram), "1")
        .CHECK_OUTPUT((ton != kilogram), "1")
        //   ////////////////////////////////////////////
        .setname("sanity test = > comparison (<) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram < gram), "0")
        .CHECK_OUTPUT((gram < kilogram), "0")
        .CHECK_OUTPUT((gram < ton), "1")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram < kilogram), "0")
        .CHECK_OUTPUT((kilogram < gram), "0")
        .CHECK_OUTPUT((kilogram < ton), "1")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton < ton), "0")
        .CHECK_OUTPUT((ton < gram), "0")
        .CHECK_OUTPUT((ton < kilogram), "0")
        //   ////////////////////////////////////////////
        .setname("sanity test = > comparison (>) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram > gram), "0")
        .CHECK_OUTPUT((gram > kilogram), "0")
        .CHECK_OUTPUT((gram > ton), "0")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram > kilogram), "0")
        .CHECK_OUTPUT((kilogram > gram), "0")
        .CHECK_OUTPUT((kilogram > ton), "0")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton > ton), "0")
        .CHECK_OUTPUT((ton > gram), "1")
        .CHECK_OUTPUT((ton > kilogram), "1")
        //   /////////////////////////////////////////////
        .setname("sanity test = > comparison (<=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram <= gram), "1")
        .CHECK_OUTPUT((gram <= kilogram), "1")
        .CHECK_OUTPUT((gram <= ton), "1")
        //   /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram <= kilogram), "1")
        .CHECK_OUTPUT((kilogram <= gram), "1")
        .CHECK_OUTPUT((kilogram <= ton), "1")
        //   ////////////////////////////////////////////
        .CHECK_OUTPUT((ton <= ton), "1")
        .CHECK_OUTPUT((ton <= gram), "0")
        .CHECK_OUTPUT((ton <= kilogram), "0")
        //   ////////////////////////////////////////////
        .setname("sanity test = > comparison (>=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram >= gram), "1")
        .CHECK_OUTPUT((gram >= kilogram), "1")
        .CHECK_OUTPUT((gram >= ton), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram >= kilogram), "1")
        .CHECK_OUTPUT((kilogram >= gram), "1")
        .CHECK_OUTPUT((kilogram >= ton), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton >= ton), "1")
        .CHECK_OUTPUT((ton >= gram), "1")
        .CHECK_OUTPUT((ton >= kilogram), "1")
        ////////////////////////////////////////////

        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sanity test = > comparison (==) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter == centimeter), "1")
        .CHECK_OUTPUT((centimeter == meter), "0")
        .CHECK_OUTPUT((centimeter == kilometer), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter == meter), "1")
        .CHECK_OUTPUT((meter == centimeter), "0")
        .CHECK_OUTPUT((meter == kilometer), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer == kilometer), "1")
        .CHECK_OUTPUT((kilometer == centimeter), "0")
        .CHECK_OUTPUT((kilometer == meter), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (!=) = >CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter != centimeter), "0")
        .CHECK_OUTPUT((centimeter != meter), "1")
        .CHECK_OUTPUT((centimeter != kilometer), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter != meter), "0")
        .CHECK_OUTPUT((meter != centimeter), "1")
        .CHECK_OUTPUT((meter != kilometer), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer != kilometer), "0")
        .CHECK_OUTPUT((kilometer != centimeter), "1")
        .CHECK_OUTPUT((kilometer != meter), "1")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (<) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter < centimeter), "0")
        .CHECK_OUTPUT((centimeter < meter), "1")
        .CHECK_OUTPUT((centimeter < kilometer), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter < meter), "0")
        .CHECK_OUTPUT((meter < centimeter), "0")
        .CHECK_OUTPUT((meter < kilometer), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer < kilometer), "0")
        .CHECK_OUTPUT((kilometer < centimeter), "0")
        .CHECK_OUTPUT((kilometer < meter), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (>) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter > centimeter), "0")
        .CHECK_OUTPUT((centimeter > meter), "0")
        .CHECK_OUTPUT((centimeter > kilometer), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter > meter), "0")
        .CHECK_OUTPUT((meter > centimeter), "1")
        .CHECK_OUTPUT((meter > kilometer), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer > kilometer), "0")
        .CHECK_OUTPUT((kilometer > centimeter), "1")
        .CHECK_OUTPUT((kilometer > meter), "1")
        /////////////////////////////////////////////
        .setname("sanity test = > comparison (<=) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter <= centimeter), "1")
        .CHECK_OUTPUT((centimeter <= meter), "1")
        .CHECK_OUTPUT((centimeter <= kilometer), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter <= meter), "1")
        .CHECK_OUTPUT((meter <= centimeter), "0")
        .CHECK_OUTPUT((meter <= kilometer), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer <= kilometer), "1")
        .CHECK_OUTPUT((kilometer <= centimeter), "0")
        .CHECK_OUTPUT((kilometer <= meter), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (>=) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter >= centimeter), "1")
        .CHECK_OUTPUT((centimeter >= meter), "0")
        .CHECK_OUTPUT((centimeter >= kilometer), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter >= meter), "1")
        .CHECK_OUTPUT((meter >= centimeter), "1")
        .CHECK_OUTPUT((meter >= kilometer), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer >= kilometer), "1")
        .CHECK_OUTPUT((kilometer >= centimeter), "1")
        .CHECK_OUTPUT((kilometer >= meter), "1")
        ////////////////////////////////////////////

        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sanity test = > comparison (==) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second == second), "1")
        .CHECK_OUTPUT((second == minute), "0")
        .CHECK_OUTPUT((second == hour), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute == minute), "1")
        .CHECK_OUTPUT((minute == second), "0")
        .CHECK_OUTPUT((minute == hour), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour == hour), "1")
        .CHECK_OUTPUT((hour == second), "0")
        .CHECK_OUTPUT((hour == minute), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (!=) = >SEC - MIN - HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second != second), "0")
        .CHECK_OUTPUT((second != minute), "1")
        .CHECK_OUTPUT((second != hour), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute != minute), "0")
        .CHECK_OUTPUT((minute != second), "1")
        .CHECK_OUTPUT((minute != hour), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour != hour), "0")
        .CHECK_OUTPUT((hour != second), "1")
        .CHECK_OUTPUT((hour != minute), "1")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (<) = > SEC - MIN - HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second < second), "0")
        .CHECK_OUTPUT((second < minute), "0")
        .CHECK_OUTPUT((second < hour), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute < minute), "0")
        .CHECK_OUTPUT((minute < second), "1")
        .CHECK_OUTPUT((minute < hour), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour < hour), "0")
        .CHECK_OUTPUT((hour < second), "0")
        .CHECK_OUTPUT((hour < minute), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (>) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second > second), "0")
        .CHECK_OUTPUT((second > minute), "1")
        .CHECK_OUTPUT((second > hour), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute > minute), "0")
        .CHECK_OUTPUT((minute > second), "0")
        .CHECK_OUTPUT((minute > hour), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour > hour), "0")
        .CHECK_OUTPUT((hour > second), "1")
        .CHECK_OUTPUT((hour > minute), "1")
        /////////////////////////////////////////////
        .setname("sanity test = > comparison (<=) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second <= second), "1")
        .CHECK_OUTPUT((second <= minute), "0")
        .CHECK_OUTPUT((second <= hour), "1")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute <= minute), "1")
        .CHECK_OUTPUT((minute <= second), "1")
        .CHECK_OUTPUT((minute <= hour), "1")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour <= hour), "1")
        .CHECK_OUTPUT((hour <= second), "0")
        .CHECK_OUTPUT((hour <= minute), "0")
        ////////////////////////////////////////////
        .setname("sanity test = > comparison (>=) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second >= second), "1")
        .CHECK_OUTPUT((second >= minute), "1")
        .CHECK_OUTPUT((second >= hour), "0")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute >= minute), "1")
        .CHECK_OUTPUT((minute >= second), "0")
        .CHECK_OUTPUT((minute >= hour), "0")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour >= hour), "1")
        .CHECK_OUTPUT((hour >= second), "1")
        .CHECK_OUTPUT((hour >= minute), "1");
    ////////////////////////////////////////////

    //   // increment decrement testing:
    gram = PhysicalNumber(5, Unit::G);
    kilogram = PhysicalNumber(6, Unit::KG);
    ton = PhysicalNumber(0.7, Unit::TON);
    centimeter = PhysicalNumber(-8, Unit::CM);
    meter = PhysicalNumber(9, Unit::M);
    kilometer = PhysicalNumber(3, Unit::KM);
    second = PhysicalNumber(11, Unit::SEC);
    minute = PhysicalNumber(-12, Unit::MIN);
    hour = PhysicalNumber(0.5, Unit::HOUR);
    testcase

        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sanity test = > gram increment decrement")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram++), "5[g]")
        .CHECK_OUTPUT(gram, "6[g]")
        .CHECK_OUTPUT((++gram), "7[g]")
        .CHECK_OUTPUT((gram--), "7[g]")
        .CHECK_OUTPUT(gram, "6[g]")
        .CHECK_OUTPUT((--gram), "5[g]")
        /////////////////////////////////////////////
        .setname("sanity test = > kilogram increment decrement")
        .CHECK_OUTPUT((kilogram++), "6[kg]")
        .CHECK_OUTPUT(kilogram, "7[kg]")
        .CHECK_OUTPUT((++kilogram), "8[kg]")
        .CHECK_OUTPUT((kilogram--), "8[kg]")
        .CHECK_OUTPUT(kilogram, "7[kg]")
        .CHECK_OUTPUT((--kilogram), "6[kg]")
        // // ////////////////////////////////////////////
        .setname("sanity test = > ton increment decrement")
        .CHECK_OUTPUT((ton++), "0.7[ton]")
        .CHECK_OUTPUT(ton, "1.7[ton]")
        .CHECK_OUTPUT((++ton), "2.7[ton]")
        .CHECK_OUTPUT((ton--), "2.7[ton]")
        .CHECK_OUTPUT(ton, "1.7[ton]")
        .CHECK_OUTPUT((--ton), "0.7[ton]")
        ////////////////////////////////////////////
        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sanity test = > centimeter increment decrement")
        .CHECK_OUTPUT((centimeter++), "-8[cm]")
        .CHECK_OUTPUT(centimeter, "-7[cm]")
        .CHECK_OUTPUT((++centimeter), "-6[cm]")
        .CHECK_OUTPUT((centimeter--), "-6[cm]")
        .CHECK_OUTPUT(centimeter, "-7[cm]")
        .CHECK_OUTPUT((--centimeter), "-8[cm]")
        // //////////////////////////////////////////////
        .setname("sanity test = > meter increment decrement")
        .CHECK_OUTPUT((meter++), "9[m]")
        .CHECK_OUTPUT(meter, "10[m]")
        .CHECK_OUTPUT((++meter), "11[m]")
        .CHECK_OUTPUT((meter--), "11[m]")
        .CHECK_OUTPUT(meter, "10[m]")
        .CHECK_OUTPUT((--meter), "9[m]")
        // /////////////////////////////////////////////
        .setname("sanity test = > kilometer increment decrement")
        .CHECK_OUTPUT((kilometer++), "3[km]")
        .CHECK_OUTPUT(kilometer, "4[km]")
        .CHECK_OUTPUT((++++kilometer), "6[km]")
        .CHECK_OUTPUT((kilometer--), "6[km]")
        .CHECK_OUTPUT(kilometer, "5[km]")
        .CHECK_OUTPUT((--kilometer), "4[km]")
        // ////////////////////////////////////////////
        // /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sanity test = > second increment decrement")
        .CHECK_OUTPUT((second++), "11[sec]")
        .CHECK_OUTPUT(second, "12[sec]")
        .CHECK_OUTPUT((++++second), "14[sec]")
        .CHECK_OUTPUT((second--), "14[sec]")
        .CHECK_OUTPUT(second, "13[sec]")
        .CHECK_OUTPUT((--second), "12[sec]")
        ////////////////////////////////////////////
        .setname("sanity test = > minute increment decrement")
        .CHECK_OUTPUT((minute++), "-12[min]")
        .CHECK_OUTPUT(minute, "-11[min]")
        .CHECK_OUTPUT((++minute), "-10[min]")
        .CHECK_OUTPUT((minute--), "-10[min]")
        .CHECK_OUTPUT(minute, "-11[min]")
        .CHECK_OUTPUT((--minute), "-12[min]")
        //////////////////////////////////////////////
        .setname("sanity test = > hour increment decrement")
        .CHECK_OUTPUT((hour++), "0.5[hour]")
        .CHECK_OUTPUT(hour, "1.5[hour]")
        .CHECK_OUTPUT((++hour), "2.5[hour]")
        .CHECK_OUTPUT((hour--), "2.5[hour]")
        .CHECK_OUTPUT(hour, "1.5[hour]")
        .CHECK_OUTPUT((--hour), "0.5[hour]")
        // /////////////////////////////////////////////

        // IO testing:
        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sanity test = > gram '>>' test")
        .CHECK_OK(istringstream("7[g]") >> gram)
        .CHECK_OUTPUT(gram, "7[g]")
        /////////////////////////////////////////////
        .setname("sanity test = > kilogram '>>' test")
        .CHECK_OK(istringstream("777[kg]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("sanity test = > ton '>>' test")
        .CHECK_OK(istringstream("3[ton]") >> ton)
        .CHECK_OUTPUT(ton, "3[ton]")
        // ////////////////////////////////////////////
        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        ////////////////////////////////////////////
        .setname("sanity test = > centimeter '>>' test")
        .CHECK_OK(istringstream("33[cm]") >> centimeter)
        .CHECK_OUTPUT(centimeter, "33[cm]")
        //////////////////////////////////////////
        .setname("sanity test = > meter '>>' test")
        .CHECK_OK(istringstream("7[m]") >> meter)
        .CHECK_OUTPUT(meter, "7[m]")
        ////////////////////////////////////////////
        .setname("sanity test = > kilometer '>>' test")
        .CHECK_OK(istringstream("2.5[km]") >> kilometer)
        .CHECK_OUTPUT(kilometer, "2.5[km]")
        ////////////////////////////////////////////
        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        ////////////////////////////////////////////
        .setname("sanity test = > sec '>>' test")
        .CHECK_OK(istringstream("3.333[sec]") >> second)
        .CHECK_OUTPUT(second, "3.333[sec]")
        ////////////////////////////////////////////
        .setname("sanity test = > minute '>>' test")
        .CHECK_OK(istringstream("7[min]") >> minute)
        .CHECK_OUTPUT(minute, "7[min]")
        ////////////////////////////////////////////
        .setname("sanity test = > hour '>>' test")
        .CHECK_OK(istringstream("0.5[hour]") >> hour)
        .CHECK_OUTPUT(hour, "0.5[hour]")
        //////////////////////////////////////////
        
        // // IO testing -  Illegal input:
        // /////////////////////////////////////////////
        .setname("Illegal input [letter-numbers] = > kilogram '>>' test")
        .CHECK_OK(istringstream("abcd[kg]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        /////////////////////////////////////////////
        .setname("Illegal input [wrong unit type] = > kilogram '>>' test")
        .CHECK_OK(istringstream("70[abbsbsbs]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [wrong unit type & letter-numbers] = > kilogram '>>' test")
        .CHECK_OK(istringstream("70[abbsbsbs]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [no numbers] = > kilogram '>>' test")
        .CHECK_OK(istringstream("[kg]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [wrong unit type & no numbers] = > kilogram '>>' test")
        .CHECK_OK(istringstream("[dfsdfdsaf]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [no unit type] = > kilogram '>>' test")
        .CHECK_OK(istringstream("60[]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [empty input string] = > kilogram '>>' test")
        .CHECK_OK(istringstream("") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [only ']'] = > kilogram '>>' test")
        .CHECK_OK(istringstream("]") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////
        .setname("Illegal input [gibberish only] = > kilogram '>>' test")
        .CHECK_OK(istringstream("dfsadfdsfsdf") >> kilogram)
        .CHECK_OUTPUT(kilogram, "777[kg]")
        ////////////////////////////////////////////

        // 2. every unit-type tested with unit-types which should NOT work - with every operator

        // arithmetic testing:
        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sanity test = > gram arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(gram + centimeter)
        .CHECK_THROWS(gram + meter)
        .CHECK_THROWS(gram + kilometer)
        .CHECK_THROWS(gram + second)
        .CHECK_THROWS(gram + minute)
        .CHECK_THROWS(gram + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilogram arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilogram + centimeter)
        .CHECK_THROWS(kilogram + meter)
        .CHECK_THROWS(kilogram + kilometer)
        .CHECK_THROWS(kilogram + second)
        .CHECK_THROWS(kilogram + minute)
        .CHECK_THROWS(kilogram + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > ton arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(ton + centimeter)
        .CHECK_THROWS(ton + meter)
        .CHECK_THROWS(ton + kilometer)
        .CHECK_THROWS(ton + second)
        .CHECK_THROWS(ton + minute)
        .CHECK_THROWS(ton + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > gram arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(gram - centimeter)
        .CHECK_THROWS(gram - meter)
        .CHECK_THROWS(gram - kilometer)
        .CHECK_THROWS(gram - second)
        .CHECK_THROWS(gram - minute)
        .CHECK_THROWS(gram - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilogram arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilogram - centimeter)
        .CHECK_THROWS(kilogram - meter)
        .CHECK_THROWS(kilogram - kilometer)
        .CHECK_THROWS(kilogram - second)
        .CHECK_THROWS(kilogram - minute)
        .CHECK_THROWS(kilogram - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > ton arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(ton - centimeter)
        .CHECK_THROWS(ton - meter)
        .CHECK_THROWS(ton - kilometer)
        .CHECK_THROWS(ton - second)
        .CHECK_THROWS(ton - minute)
        .CHECK_THROWS(ton - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > gram arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(gram += centimeter)
        .CHECK_THROWS(gram += meter)
        .CHECK_THROWS(gram += kilometer)
        .CHECK_THROWS(gram += second)
        .CHECK_THROWS(gram += minute)
        .CHECK_THROWS(gram += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilogram arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilogram += centimeter)
        .CHECK_THROWS(kilogram += meter)
        .CHECK_THROWS(kilogram += kilometer)
        .CHECK_THROWS(kilogram += second)
        .CHECK_THROWS(kilogram += minute)
        .CHECK_THROWS(kilogram += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > ton arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(ton += centimeter)
        .CHECK_THROWS(ton += meter)
        .CHECK_THROWS(ton += kilometer)
        .CHECK_THROWS(ton += second)
        .CHECK_THROWS(ton += minute)
        .CHECK_THROWS(ton += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > gram arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(gram -= centimeter)
        .CHECK_THROWS(gram -= meter)
        .CHECK_THROWS(gram -= kilometer)
        .CHECK_THROWS(gram -= second)
        .CHECK_THROWS(gram -= minute)
        .CHECK_THROWS(gram -= hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilogram arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilogram -= centimeter)
        .CHECK_THROWS(kilogram -= meter)
        .CHECK_THROWS(kilogram -= kilometer)
        .CHECK_THROWS(kilogram -= second)
        .CHECK_THROWS(kilogram -= minute)
        .CHECK_THROWS(kilogram -= hour)
        //////////////////////////////////////////////
        .setname("sanity test = > ton arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(ton -= centimeter)
        .CHECK_THROWS(ton -= meter)
        .CHECK_THROWS(ton -= kilometer)
        .CHECK_THROWS(ton -= second)
        .CHECK_THROWS(ton -= minute)
        .CHECK_THROWS(ton -= hour)
        //////////////////////////////////////////////

        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sanity test = > centimeter arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(centimeter + gram)
        .CHECK_THROWS(centimeter + kilogram)
        .CHECK_THROWS(centimeter + ton)
        .CHECK_THROWS(centimeter + second)
        .CHECK_THROWS(centimeter + minute)
        .CHECK_THROWS(centimeter + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > meter arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(meter + gram)
        .CHECK_THROWS(meter + kilogram)
        .CHECK_THROWS(meter + ton)
        .CHECK_THROWS(meter + second)
        .CHECK_THROWS(meter + minute)
        .CHECK_THROWS(meter + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilometer arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilometer + gram)
        .CHECK_THROWS(kilometer + kilogram)
        .CHECK_THROWS(kilometer + ton)
        .CHECK_THROWS(kilometer + second)
        .CHECK_THROWS(kilometer + minute)
        .CHECK_THROWS(kilometer + hour)
        //////////////////////////////////////////////
        .setname("sanity test = > centimeter arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(centimeter - gram)
        .CHECK_THROWS(centimeter - kilogram)
        .CHECK_THROWS(centimeter - ton)
        .CHECK_THROWS(centimeter - second)
        .CHECK_THROWS(centimeter - minute)
        .CHECK_THROWS(centimeter - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > meter arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(meter - gram)
        .CHECK_THROWS(meter - kilogram)
        .CHECK_THROWS(meter - ton)
        .CHECK_THROWS(meter - second)
        .CHECK_THROWS(meter - minute)
        .CHECK_THROWS(meter - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilometer arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilometer - gram)
        .CHECK_THROWS(kilometer - kilogram)
        .CHECK_THROWS(kilometer - ton)
        .CHECK_THROWS(kilometer - second)
        .CHECK_THROWS(kilometer - minute)
        .CHECK_THROWS(kilometer - hour)
        //////////////////////////////////////////////
        .setname("sanity test = > centimeter arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(centimeter += gram)
        .CHECK_THROWS(centimeter += kilogram)
        .CHECK_THROWS(centimeter += ton)
        .CHECK_THROWS(centimeter += second)
        .CHECK_THROWS(centimeter += minute)
        .CHECK_THROWS(centimeter += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > meter arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(meter += gram)
        .CHECK_THROWS(meter += kilogram)
        .CHECK_THROWS(meter += ton)
        .CHECK_THROWS(meter += second)
        .CHECK_THROWS(meter += minute)
        .CHECK_THROWS(meter += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilometer arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilometer += gram)
        .CHECK_THROWS(kilometer += kilogram)
        .CHECK_THROWS(kilometer += ton)
        .CHECK_THROWS(kilometer += second)
        .CHECK_THROWS(kilometer += minute)
        .CHECK_THROWS(kilometer += hour)
        //////////////////////////////////////////////
        .setname("sanity test = > centimeter arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(centimeter -= gram)
        .CHECK_THROWS(centimeter -= kilogram)
        .CHECK_THROWS(centimeter -= ton)
        .CHECK_THROWS(centimeter -= second)
        .CHECK_THROWS(centimeter -= minute)
        .CHECK_THROWS(centimeter -= hour)
        //////////////////////////////////////////////
        .setname("sanity test = > meter arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(meter -= gram)
        .CHECK_THROWS(meter -= kilogram)
        .CHECK_THROWS(meter -= ton)
        .CHECK_THROWS(meter -= second)
        .CHECK_THROWS(meter -= minute)
        .CHECK_THROWS(meter -= hour)
        //////////////////////////////////////////////
        .setname("sanity test = > kilometer arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(kilometer -= gram)
        .CHECK_THROWS(kilometer -= kilogram)
        .CHECK_THROWS(kilometer -= ton)
        .CHECK_THROWS(kilometer -= second)
        .CHECK_THROWS(kilometer -= minute)
        .CHECK_THROWS(kilometer -= hour)
        //////////////////////////////////////////////

        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sanity test = > second arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(second + gram)
        .CHECK_THROWS(second + kilogram)
        .CHECK_THROWS(second + ton)
        .CHECK_THROWS(second + centimeter)
        .CHECK_THROWS(second + meter)
        .CHECK_THROWS(second + kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > minute arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(minute + gram)
        .CHECK_THROWS(minute + kilogram)
        .CHECK_THROWS(minute + ton)
        .CHECK_THROWS(minute + centimeter)
        .CHECK_THROWS(minute + meter)
        .CHECK_THROWS(minute + kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > hour arithmetic(+) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(hour + gram)
        .CHECK_THROWS(hour + kilogram)
        .CHECK_THROWS(hour + ton)
        .CHECK_THROWS(hour + centimeter)
        .CHECK_THROWS(hour + meter)
        .CHECK_THROWS(hour + kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > second arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(second - gram)
        .CHECK_THROWS(second - kilogram)
        .CHECK_THROWS(second - ton)
        .CHECK_THROWS(second - centimeter)
        .CHECK_THROWS(second - meter)
        .CHECK_THROWS(second - kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > minute arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(minute - gram)
        .CHECK_THROWS(minute - kilogram)
        .CHECK_THROWS(minute - ton)
        .CHECK_THROWS(minute - centimeter)
        .CHECK_THROWS(minute - meter)
        .CHECK_THROWS(minute - kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > hour arithmetic(-) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(hour - gram)
        .CHECK_THROWS(hour - kilogram)
        .CHECK_THROWS(hour - ton)
        .CHECK_THROWS(hour - centimeter)
        .CHECK_THROWS(hour - meter)
        .CHECK_THROWS(hour - kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > second arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(second += gram)
        .CHECK_THROWS(second += kilogram)
        .CHECK_THROWS(second += ton)
        .CHECK_THROWS(second += centimeter)
        .CHECK_THROWS(second += meter)
        .CHECK_THROWS(second += kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > minute arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(minute += gram)
        .CHECK_THROWS(minute += kilogram)
        .CHECK_THROWS(minute += ton)
        .CHECK_THROWS(minute += centimeter)
        .CHECK_THROWS(minute += meter)
        .CHECK_THROWS(minute += kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > hour arithmetic(+=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(hour += gram)
        .CHECK_THROWS(hour += kilogram)
        .CHECK_THROWS(hour += ton)
        .CHECK_THROWS(hour += centimeter)
        .CHECK_THROWS(hour += meter)
        .CHECK_THROWS(hour += kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > second arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(second -= gram)
        .CHECK_THROWS(second -= kilogram)
        .CHECK_THROWS(second -= ton)
        .CHECK_THROWS(second -= centimeter)
        .CHECK_THROWS(second -= meter)
        .CHECK_THROWS(second -= kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > minute arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(minute -= gram)
        .CHECK_THROWS(minute -= kilogram)
        .CHECK_THROWS(minute -= ton)
        .CHECK_THROWS(minute -= centimeter)
        .CHECK_THROWS(minute -= meter)
        .CHECK_THROWS(minute -= kilometer)
        //////////////////////////////////////////////
        .setname("sanity test = > hour arithmetic(-=) should THROW!")
        //////////////////////////////////////////////
        .CHECK_THROWS(hour -= gram)
        .CHECK_THROWS(hour -= kilogram)
        .CHECK_THROWS(hour -= ton)
        .CHECK_THROWS(hour -= centimeter)
        .CHECK_THROWS(hour -= meter)
        .CHECK_THROWS(hour -= kilometer)
        //////////////////////////////////////////////
        .setname("...")

        .print(cout, /*show_grade=*/0);
    grade = testcase.grade();
  }
  else
  {
    testcase.print_signal(signal);
    grade = 0;
  }
  cout << "*** Grade: " << grade << " ***" << endl;
  return grade;
}
