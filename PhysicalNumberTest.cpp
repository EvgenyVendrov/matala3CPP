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

    // sainty test's - just cheking that all features are basicly valid:
    // init the to be tested physical numbers
    PhysicalNumber gram(5, Unit::G);
    PhysicalNumber kilogram(6, Unit::KG);
    PhysicalNumber ton(0.2, Unit::TON);
    PhysicalNumber centimeter(-5.6, Unit::CM);
    PhysicalNumber meter(50, Unit::M);
    PhysicalNumber kilometer(2.3, Unit::KM);
    PhysicalNumber second(4, Unit::SEC);
    PhysicalNumber minute(55, Unit::MIN);
    PhysicalNumber hour(0.25, Unit::HOUR);
    // 1. every unit-type tested with unit-types which should work - with every operator
    // arithmetic testing:
    testcase
        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sainty test = > arithmetic (+) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(gram + gram, "10[g]")
        .CHECK_OUTPUT(gram + kilogram, "6005[g]")
        .CHECK_OUTPUT(gram + ton, "2000005[g]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(kilogram + kilogram, "12[kg]")
        .CHECK_OUTPUT(kilogram + gram, "6.005[kg]")
        .CHECK_OUTPUT(kilogram + ton, "206[kg]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(ton + ton, "0.4[ton]")
        .CHECK_OUTPUT(ton + gram, "0.200005[ton]")
        .CHECK_OUTPUT(ton + kilogram, "0.206[ton]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(gram - gram, "0[g]")
        .CHECK_OUTPUT(gram - kilogram, "-5995[g]")
        .CHECK_OUTPUT(gram - ton, "-199995[g]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(kilogram - kilogram, "0[kg]")
        .CHECK_OUTPUT(kilogram - gram, "5.995[kg]")
        .CHECK_OUTPUT(kilogram - ton, "-194[kg]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(ton - ton, "0[ton]")
        .CHECK_OUTPUT(ton - gram, "0.199995[ton]")
        .CHECK_OUTPUT(ton - kilogram, "0.194[ton]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (+=) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram += gram), "10[g]")
        .CHECK_OUTPUT((gram += kilogram), "6005[g]")
        .CHECK_OUTPUT((gram += ton), "2000005[g]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram += kilogram), "12[kg]")
        .CHECK_OUTPUT((kilogram += gram), "6.005[kg]")
        .CHECK_OUTPUT((kilogram += ton), "206[kg]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton += ton), "0.4[ton]")
        .CHECK_OUTPUT((ton += gram), "0.200005[ton]")
        .CHECK_OUTPUT((ton += kilogram), "0.206[ton]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (+) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(+gram, "5[g]")
        .CHECK_OUTPUT(+kilogram, "6[kg]")
        .CHECK_OUTPUT(+ton, "0.2[ton]")
        /////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-=) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram -= gram), "0[g]")
        .CHECK_OUTPUT((gram -= kilogram), "-5995[g]")
        .CHECK_OUTPUT((gram -= ton), "-199995[g]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram -= kilogram), "0[kg]")
        .CHECK_OUTPUT((kilogram -= gram), "5.995[kg]")
        .CHECK_OUTPUT((kilogram -= ton), "-194[kg]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton -= ton), "0[ton]")
        .CHECK_OUTPUT((ton -= gram), "0.199995[ton]")
        .CHECK_OUTPUT((ton -= kilogram), "0.194[ton]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (-) = > should work = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-gram, "-5[g]")
        .CHECK_OUTPUT(-kilogram, "-6[kg]")
        .CHECK_OUTPUT(-ton, "-0.2[ton]")
        //////////////////////////////////////////////

        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sainty test = > arithmetic (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(centimeter + centimeter, "-11.2[cm]")
        .CHECK_OUTPUT(centimeter + minute, "4994.4[cm]")
        .CHECK_OUTPUT(centimeter + kilometer, "229994.4[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(meter + meter, "100[m]")
        .CHECK_OUTPUT(meter + second, "49.944[m]")
        .CHECK_OUTPUT(meter + kilometer, "2350[m]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(kilometer + kilometer, "4.6[km]")
        .CHECK_OUTPUT(kilometer + centimeter, "2.299944[km]")
        .CHECK_OUTPUT(kilometer + meter, "2.35[km]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(centimeter - centimeter, "0[cm]")
        .CHECK_OUTPUT(centimeter - meter, "-5005.6[cm]")
        .CHECK_OUTPUT(centimeter - kilometer, "-230005.6[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(meter - meter, "0[m]")
        .CHECK_OUTPUT(meter - centimeter, "50.056[m]")
        .CHECK_OUTPUT(meter - kilometer, "-2250[m]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(kilometer - kilometer, "0[km]")
        .CHECK_OUTPUT(kilometer - centimeter, "2.300056[km]")
        .CHECK_OUTPUT(kilometer - meter, "2.25[km]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (+=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter += centimeter), "-11.2[cm]")
        .CHECK_OUTPUT((centimeter += meter), "4994.4[cm]")
        .CHECK_OUTPUT((centimeter += kilometer), "229994.4[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter += meter), "100[m]")
        .CHECK_OUTPUT((meter += centimeter), "49.944[m]")
        .CHECK_OUTPUT((meter += kilometer), "2350[m]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer += kilometer), "4.6[km]")
        .CHECK_OUTPUT((kilometer += centimeter), "2.299944[km]")
        .CHECK_OUTPUT((kilometer += meter), "2.35[km]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(+centimeter, "-5.6[cm]")
        .CHECK_OUTPUT(+meter, "50[m]")
        .CHECK_OUTPUT(+kilometer, "2.3[km]")
        /////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter -= centimeter), "0[cm]")
        .CHECK_OUTPUT((centimeter -= meter), "-5005.6[cm]")
        .CHECK_OUTPUT((centimeter -= kilometer), "-230005.6[cm]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter -= meter), "0[m]")
        .CHECK_OUTPUT((meter -= centimeter), "50.056[m]")
        .CHECK_OUTPUT((meter -= kilometer), "-2250[m]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer -= kilometer), "0[km]")
        .CHECK_OUTPUT((kilometer -= centimeter), "2.300056[km]")
        .CHECK_OUTPUT((kilometer -= meter), "2.25[km]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-centimeter, "5.6[cm]")
        .CHECK_OUTPUT(-meter, "-50[m]")
        .CHECK_OUTPUT(-kilometer, "-2.3[km]")
        //////////////////////////////////////////////

        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sainty test = > arithmetic (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(second + second, "8[sec]")
        .CHECK_OUTPUT(second + minute, "3304[sec]")
        .CHECK_OUTPUT(second + hour, "1504[sec]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(minute + minute, "110[min]")
        .CHECK_OUTPUT(minute + second, "55.0666[min]")
        .CHECK_OUTPUT(minute + hour, "70[min]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(hour + hour, "0.5[hour]")
        .CHECK_OUTPUT(hour + second, "0.261[hour]")
        .CHECK_OUTPUT(hour + minute, "1.166[hour]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(second - second, "0[sec]")
        .CHECK_OUTPUT(second - minute, "-3296[sec]")
        .CHECK_OUTPUT(second - hour, "-896[sec]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT(minute - minute, "0[min]")
        .CHECK_OUTPUT(minute - second, "50.056[min]")
        .CHECK_OUTPUT(minute - hour, "40[min]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT(hour - hour, "0[hour]")
        .CHECK_OUTPUT(hour - second, "0.24889[hour]")
        .CHECK_OUTPUT(hour - minute, "-0.666[hour]")
        ////////////////////////////////////////////
        .setname("sainty test = > arithmetic (+=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second += second), "8[sec]")
        .CHECK_OUTPUT((second += minute), "3304[sec]")
        .CHECK_OUTPUT((second += hour), "1504[sec]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute += minute), "110[min]")
        .CHECK_OUTPUT((minute += second), "55.0666[min]")
        .CHECK_OUTPUT((minute += hour), "70[min]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour += hour), "0.5[hour]")
        .CHECK_OUTPUT((hour += second), "0.261[hour]")
        .CHECK_OUTPUT((hour += minute), "1.166[hour]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (+) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(+second, "4[sec]")
        .CHECK_OUTPUT(+minute, "55[min]")
        .CHECK_OUTPUT(+hour, "0.25[hour]")
        /////////////////////////////////////////////
        .setname("sainty test = > arithmetic (-=) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second -= second), "0[sec]")
        .CHECK_OUTPUT((second -= minute), "-3296[sec]")
        .CHECK_OUTPUT((second -= hour), "-896[sec]")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute -= minute), "0[min]")
        .CHECK_OUTPUT((minute -= second), "50.056[min]")
        .CHECK_OUTPUT((minute -= hour), "40[min]")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour -= hour), "0[hour]")
        .CHECK_OUTPUT((hour -= second), "0.24889[hour]")
        .CHECK_OUTPUT((hour -= minute), "-0.666[hour]")
        ////////////////////////////////////////////
        .setname("sainty test = > unary (-) = > should work = > CM-M-KM")
        //////////////////////////////////////////////
        .CHECK_OUTPUT(-second, "-4[sec]")
        .CHECK_OUTPUT(-minute, "-55[min]")
        .CHECK_OUTPUT(-hour, "-0.25[hour]")
        //////////////////////////////////////////////

        // comparison testing:

        /*********************************************/
        // G - KG - TON tests//
        /*********************************************/
        .setname("sainty test = > comparison (==) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram == gram), "true")
        .CHECK_OUTPUT((gram == kilogram), "false")
        .CHECK_OUTPUT((gram == ton), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram == kilogram), "true")
        .CHECK_OUTPUT((kilogram == gram), "false")
        .CHECK_OUTPUT((kilogram == ton), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton == ton), "true")
        .CHECK_OUTPUT((ton == gram), "false")
        .CHECK_OUTPUT((ton == kilogram), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (!=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram != gram), "false")
        .CHECK_OUTPUT((gram != kilogram), "true")
        .CHECK_OUTPUT((gram != ton), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram != kilogram), "false")
        .CHECK_OUTPUT((kilogram != gram), "true")
        .CHECK_OUTPUT((kilogram != ton), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton != ton), "false")
        .CHECK_OUTPUT((ton != gram), "true")
        .CHECK_OUTPUT((ton != kilogram), "true")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (<) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram < gram), "false")
        .CHECK_OUTPUT((gram < kilogram), "true")
        .CHECK_OUTPUT((gram < ton), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram < kilogram), "false")
        .CHECK_OUTPUT((kilogram < gram), "false")
        .CHECK_OUTPUT((kilogram < ton), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton < ton), "false")
        .CHECK_OUTPUT((ton < gram), "false")
        .CHECK_OUTPUT((ton < kilogram), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram > gram), "false")
        .CHECK_OUTPUT((gram > kilogram), "true")
        .CHECK_OUTPUT((gram > ton), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram > kilogram), "false")
        .CHECK_OUTPUT((kilogram > gram), "true")
        .CHECK_OUTPUT((kilogram > ton), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton > ton), "false")
        .CHECK_OUTPUT((ton > gram), "true")
        .CHECK_OUTPUT((ton > kilogram), "true")
        /////////////////////////////////////////////
        .setname("sainty test = > comparison (<=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram <= gram), "true")
        .CHECK_OUTPUT((gram <= kilogram), "true")
        .CHECK_OUTPUT((gram <= ton), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram <= kilogram), "true")
        .CHECK_OUTPUT((kilogram <= gram), "false")
        .CHECK_OUTPUT((kilogram <= ton), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton <= ton), "true")
        .CHECK_OUTPUT((ton <= gram), "false")
        .CHECK_OUTPUT((ton <= kilogram), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>=) = > G-KG-TON")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((gram >= gram), "true")
        .CHECK_OUTPUT((gram >= kilogram), "false")
        .CHECK_OUTPUT((gram >= ton), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((kilogram >= kilogram), "true")
        .CHECK_OUTPUT((kilogram >= gram), "true")
        .CHECK_OUTPUT((kilogram >= ton), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((ton >= ton), "true")
        .CHECK_OUTPUT((ton >= gram), "true")
        .CHECK_OUTPUT((ton >= kilogram), "true")
        ////////////////////////////////////////////

        /*********************************************/
        // CM - M - KM tests//
        /*********************************************/
        .setname("sainty test = > comparison (==) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter == centimeter), "true")
        .CHECK_OUTPUT((centimeter == meter), "false")
        .CHECK_OUTPUT((centimeter == kilometer), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter == meter), "true")
        .CHECK_OUTPUT((meter == centimeter), "false")
        .CHECK_OUTPUT((meter == kilometer), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer == kilometer), "true")
        .CHECK_OUTPUT((kilometer == centimeter), "false")
        .CHECK_OUTPUT((kilometer == meter), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (!=) = >CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter != centimeter), "false")
        .CHECK_OUTPUT((centimeter != meter), "true")
        .CHECK_OUTPUT((centimeter != kilometer), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter != meter), "false")
        .CHECK_OUTPUT((meter != centimeter), "true")
        .CHECK_OUTPUT((meter != kilometer), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer != kilometer), "false")
        .CHECK_OUTPUT((kilometer != centimeter), "true")
        .CHECK_OUTPUT((kilometer != meter), "true")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (<) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter < centimeter), "false")
        .CHECK_OUTPUT((centimeter < meter), "true")
        .CHECK_OUTPUT((centimeter < kilometer), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter < meter), "false")
        .CHECK_OUTPUT((meter < centimeter), "false")
        .CHECK_OUTPUT((meter < kilometer), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer < kilometer), "false")
        .CHECK_OUTPUT((kilometer < centimeter), "false")
        .CHECK_OUTPUT((kilometer < meter), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter > centimeter), "false")
        .CHECK_OUTPUT((centimeter > meter), "true")
        .CHECK_OUTPUT((centimeter > kilometer), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter > meter), "false")
        .CHECK_OUTPUT((meter > centimeter), "true")
        .CHECK_OUTPUT((meter > kilometer), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer > kilometer), "false")
        .CHECK_OUTPUT((kilometer > centimeter), "true")
        .CHECK_OUTPUT((kilometer > meter), "true")
        /////////////////////////////////////////////
        .setname("sainty test = > comparison (<=) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter <= centimeter), "true")
        .CHECK_OUTPUT((centimeter <= meter), "true")
        .CHECK_OUTPUT((centimeter <= kilometer), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter <= meter), "true")
        .CHECK_OUTPUT((meter <= centimeter), "false")
        .CHECK_OUTPUT((meter <= kilometer), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer <= kilometer), "true")
        .CHECK_OUTPUT((kilometer <= centimeter), "false")
        .CHECK_OUTPUT((kilometer <= meter), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>=) = > CM - M - KM ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((centimeter >= centimeter), "true")
        .CHECK_OUTPUT((centimeter >= meter), "false")
        .CHECK_OUTPUT((centimeter >= kilometer), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((meter >= meter), "true")
        .CHECK_OUTPUT((meter >= centimeter), "true")
        .CHECK_OUTPUT((meter >= kilometer), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((kilometer >= kilometer), "true")
        .CHECK_OUTPUT((kilometer >= centimeter), "true")
        .CHECK_OUTPUT((kilometer >= meter), "true")
        ////////////////////////////////////////////

        /*********************************************/
        // SEC - MIN - HOUR tests//
        /*********************************************/
        .setname("sainty test = > comparison (==) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second == second), "true")
        .CHECK_OUTPUT((second == minute), "false")
        .CHECK_OUTPUT((second == hour), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute == minute), "true")
        .CHECK_OUTPUT((minute == second), "false")
        .CHECK_OUTPUT((minute == hour), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour == hour), "true")
        .CHECK_OUTPUT((hour == second), "false")
        .CHECK_OUTPUT((hour == minute), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (!=) = >SEC - MIN - HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second != second), "false")
        .CHECK_OUTPUT((second != minute), "true")
        .CHECK_OUTPUT((second != hour), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute != minute), "false")
        .CHECK_OUTPUT((minute != second), "true")
        .CHECK_OUTPUT((minute != hour), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour != hour), "false")
        .CHECK_OUTPUT((hour != second), "true")
        .CHECK_OUTPUT((hour != minute), "true")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (<) = > SEC - MIN - HOUR")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second < second), "false")
        .CHECK_OUTPUT((second < minute), "true")
        .CHECK_OUTPUT((second < hour), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute < minute), "false")
        .CHECK_OUTPUT((minute < second), "false")
        .CHECK_OUTPUT((minute < hour), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour < hour), "false")
        .CHECK_OUTPUT((hour < second), "false")
        .CHECK_OUTPUT((hour < minute), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second > second), "false")
        .CHECK_OUTPUT((second > minute), "true")
        .CHECK_OUTPUT((second > hour), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute > minute), "false")
        .CHECK_OUTPUT((minute > second), "true")
        .CHECK_OUTPUT((minute > hour), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour > hour), "false")
        .CHECK_OUTPUT((hour > second), "true")
        .CHECK_OUTPUT((hour > minute), "true")
        /////////////////////////////////////////////
        .setname("sainty test = > comparison (<=) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second <= second), "true")
        .CHECK_OUTPUT((second <= minute), "true")
        .CHECK_OUTPUT((second <= hour), "true")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute <= minute), "true")
        .CHECK_OUTPUT((minute <= second), "false")
        .CHECK_OUTPUT((minute <= hour), "true")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour <= hour), "true")
        .CHECK_OUTPUT((hour <= second), "false")
        .CHECK_OUTPUT((hour <= minute), "false")
        ////////////////////////////////////////////
        .setname("sainty test = > comparison (>=) = > SEC - MIN - HOUR ")
        //////////////////////////////////////////////
        .CHECK_OUTPUT((second >= second), "true")
        .CHECK_OUTPUT((second >= minute), "false")
        .CHECK_OUTPUT((second >= hour), "false")
        /////////////////////////////////////////////
        .CHECK_OUTPUT((minute >= minute), "true")
        .CHECK_OUTPUT((minute >= second), "true")
        .CHECK_OUTPUT((minute >= hour), "false")
        ////////////////////////////////////////////
        .CHECK_OUTPUT((hour >= hour), "true")
        .CHECK_OUTPUT((hour >= second), "true")
        .CHECK_OUTPUT((hour >= minute), "true")
        ////////////////////////////////////////////

        .setname("...")

        .print(cout, /*show_grade=*/false);
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
