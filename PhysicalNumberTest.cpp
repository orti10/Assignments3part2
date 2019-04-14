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

    PhysicalNumber cm(3000, Unit::CM);
    PhysicalNumber sec(60, Unit::SEC);
    PhysicalNumber ton(2, Unit::TON);
    PhysicalNumber kg(30, Unit::KG);
    PhysicalNumber g(500, Unit::G);
    PhysicalNumber p1(2, Unit::KM);
    PhysicalNumber p2(300, Unit::M);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(sec, "60[sec]")
    .CHECK_OUTPUT(ton, "2[ton]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("30[kg]") >> kg)
    .CHECK_OUTPUT((kg += PhysicalNumber(1, Unit::TON)), "1030[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
    .setname("Basic correct output")
    .CHECK_OUTPUT(cm, "3000[cm]")
    .CHECK_OUTPUT(ton, "2[ton]")
    .CHECK_OUTPUT(g, "500[g]")
    .CHECK_OUTPUT(sec, "60[sec]")
    .CHECK_OUTPUT(kg, "1030[kg]")

    .setname("Compatible correct dimensions")
    .CHECK_OUTPUT(cm+cm, "6000[cm]")
    .CHECK_OUTPUT((ton+=kg), "3.03[ton]")
    .CHECK_OUTPUT(ton, "3.03[ton]")
    .CHECK_OUTPUT(sec++, "61[sec]")
    .CHECK_OUTPUT(++g, "501[g]")
    .CHECK_OUTPUT(--g, "500[g]")
    .CHECK_OUTPUT(ton-kg, "2[ton]")
    .CHECK_OUTPUT((kg-=g), "1029.5[kg]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(cm+sec)
    .CHECK_THROWS(cm+ton)
    .CHECK_THROWS(kg-sec)
    .CHECK_THROWS(ton-=sec)
    .CHECK_THROWS(cm+ton)
    .CHECK_THROWS(kg-sec)
    .CHECK_THROWS(g-cm)
    .CHECK_THROWS(g>sec)
    .CHECK_THROWS(ton==cm)
    .CHECK_THROWS(cm<=sec)
    
    .setname("Check OK'S")
    .CHECK_OK(istringstream("500[g]")>>g)
    .CHECK_OK(istringstream("6000[cm]")>>cm)
    .CHECK_OK(istringstream("2.3[ton]")>>ton)
    .CHECK_OK(istringstream("61[sec]")>>sec)
    .CHECK_OK(istringstream("1029.5[kg]")>>kg)

    .setname("comparsion")
    .CHECK_EQUAL(p1>p2,true)
    .CHECK_EQUAL(sec<d,true)
    .CHECK_EQUAL(kg==ton,false)
    .CHECK_OK(istringstream("1000[kg]")>>kg)
    .CHECK_OUTPUT(kg, "1000[kg]")
    .CHECK_OK(istringstream("1[ton]")>>ton)
    .CHECK_OUTPUT(ton, "1[ton]")    
    .CHECK_EQUAL(ton==kg,true)
    .CHECK_EQUAL(kg!=g,true)
    .CHECK_EQUAL(ton>g,true)
    .CHECK_EQUAL(g>kg,false)
    .CHECK_EQUAL(cm==a,false)
    .CHECK_EQUAL(c<d,false)
    
      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
