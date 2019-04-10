#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include <iostream>
#include "Unit.h"

using namespace std;

namespace ariel {
static string const endings[] = {"km","m","cm","hour","min","sec","ton","kg","g"};
class PhysicalNumber{
    private:
    Unit u;
    double num;

    bool sameUnit(const PhysicalNumber&);
    double unit_Converter(PhysicalNumber& ,PhysicalNumber&);
    
    public:
    PhysicalNumber(double number,Unit unit);
    PhysicalNumber(const PhysicalNumber& pn);

    const PhysicalNumber operator+(const PhysicalNumber&); 
	const PhysicalNumber operator-(const PhysicalNumber&);
	PhysicalNumber& operator+=(const PhysicalNumber&);
	PhysicalNumber& operator-=(const PhysicalNumber&);
	PhysicalNumber operator+(); // Unari
	PhysicalNumber operator-(); // Unari

    bool operator> (const PhysicalNumber&) ;
    bool operator< (const PhysicalNumber&) ;
    bool operator>= (const PhysicalNumber&) ;
    bool operator<= (const PhysicalNumber&) ;
    bool operator== (const PhysicalNumber&) ;
    bool operator!= (const PhysicalNumber&) ;

    PhysicalNumber operator++();//++i
    PhysicalNumber operator++(int);//i++
    PhysicalNumber operator--();//--i
    PhysicalNumber operator--(int);//i--
    
    
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);//פלט
    friend istream& operator>> (istream& is, PhysicalNumber& c);//קלט
    
    };
}
#endif
