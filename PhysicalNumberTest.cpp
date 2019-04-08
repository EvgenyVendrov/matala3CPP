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

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

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
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+cgram "150[min]")

    .setname("Incompagramible dimensions")
    .CHECK_THROWS(a+cgram
    .CHECK_THROWS(a+dgram
    .CHECK_THROWS(b+cgram
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]");

     .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

// sainty test's - just cheking that all features are basicly valid:
// init the to be tested physical numbers
PhysicalNumber gram(5 , Unit::G);
PhysicalNumber kilogram(6 , Unit::KG);
PhysicalNumber ton(0.2 , Unit::TON);
PhysicalNumber centimeter(-5.6 , Unit::CM);
PhysicalNumber meter(50 , Unit::M);
PhysicalNumber kilometer(2.3 , Unit::KM);
PhysicalNumber second(0.4 , Unit::SEC);
PhysicalNumber minute(55.5 , Unit::MIN);
PhysicalNumber hour(0.25 , Unit::HOUR);
// 1. every unit-type tested with unit-types which should work - with every operator
// arithmetic testing:
testcase
.setname("sainty test = > arithmetic (+) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(gram+gram, "10[g]")
.CHECK_OUTPUT(gram+kilogram, "6005[g]")
.CHECK_OUTPUT(gram+ton, "2000005[g]")
/////////////////////////////////////////////
.CHECK_OUTPUT(kilogram+kilogram, "12[kg]")
.CHECK_OUTPUT(kilogram+gram, "6.005[kg]")
.CHECK_OUTPUT(kilogram+ton, "206[kg]")
////////////////////////////////////////////
.CHECK_OUTPUT(ton+ton, "0.4[ton]")
.CHECK_OUTPUT(ton+gram, "0.200005[ton]")
.CHECK_OUTPUT(ton+kilogram, "0.206[ton]")
////////////////////////////////////////////
.setname("sainty test = > arithmetic (-) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(gram-gram, "0[g]")
.CHECK_OUTPUT(gram-kilogram, "-5995[g]")
.CHECK_OUTPUT(gram-ton, "-199995[g]")
/////////////////////////////////////////////
.CHECK_OUTPUT(kilogram-kilogram, "0[kg]")
.CHECK_OUTPUT(kilogram-gram, "5.995[kg]")
.CHECK_OUTPUT(kilogram-ton, "-194[kg]")
////////////////////////////////////////////
.CHECK_OUTPUT(ton-ton, "0[ton]")
.CHECK_OUTPUT(ton-gram, "0.199995[ton]")
.CHECK_OUTPUT(ton-kilogram, "0.194[ton]")
////////////////////////////////////////////
.setname("sainty test = > arithmetic (+=) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(gram+=gram, "10[g]")
.CHECK_OUTPUT(gram+=kilogram, "6005[g]")
.CHECK_OUTPUT(gram+=ton, "2000005[g]")
/////////////////////////////////////////////
.CHECK_OUTPUT(kilogram+=kilogram, "12[kg]")
.CHECK_OUTPUT(kilogram+=gram, "6.005[kg]")
.CHECK_OUTPUT(kilogram+=ton, "206[kg]")
////////////////////////////////////////////
.CHECK_OUTPUT(ton+=ton, "0.4[ton]")
.CHECK_OUTPUT(ton+=gram, "0.200005[ton]")
.CHECK_OUTPUT(ton+=kilogram, "0.206[ton]")
////////////////////////////////////////////
.setname("sainty test = > unary (+) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(+gram, "5[g]")
.CHECK_OUTPUT(+kilogram, "6[kg]")
.CHECK_OUTPUT(+ton, "0.2[ton]")
/////////////////////////////////////////////
.setname("sainty test = > arithmetic (-=) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(gram-=gram, "0[g]")
.CHECK_OUTPUT(gram-=kilogram, "-5995[g]")
.CHECK_OUTPUT(gram-=ton, "-199995[g]")
/////////////////////////////////////////////
.CHECK_OUTPUT(kilogram-=kilogram, "0[kg]")
.CHECK_OUTPUT(kilogram-=gram, "5.995[kg]")
.CHECK_OUTPUT(kilogram-=ton, "-194[kg]")
////////////////////////////////////////////
.CHECK_OUTPUT(ton-=ton, "0[ton]")
.CHECK_OUTPUT(ton-=gram, "0.199995[ton]")
.CHECK_OUTPUT(ton-=kilogram, "0.194[ton]")
////////////////////////////////////////////
setname("sainty test = > unary (-) = > should work = > G-KG-TON")
//////////////////////////////////////////////
.CHECK_OUTPUT(-gram, "-5[g]")
.CHECK_OUTPUT(-kilogram, "-6[kg]")
.CHECK_OUTPUT(-ton, "-0.2[ton]")





      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
