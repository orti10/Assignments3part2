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
    double unit_Converter(PhysicalNumber& ,PhysicalNumber&)const;
    friend istream& checkInputUnit(istream& is, PhysicalNumber& pn);
    
    public:
    
    PhysicalNumber(const double number,const Unit unit);//consts 2
    PhysicalNumber(const PhysicalNumber& pn);
    void setData(double);
    void setUnit(Unit);

    const PhysicalNumber operator+(const PhysicalNumber&)const; 
	const PhysicalNumber operator-(const PhysicalNumber&)const;
	PhysicalNumber& operator+=(const PhysicalNumber&);
	PhysicalNumber& operator-=(const PhysicalNumber&);
	const PhysicalNumber operator+()const; // Unari
	const PhysicalNumber operator-()const; // Unari

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
    
    
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);//output
    friend istream& operator>> (istream& is, PhysicalNumber& c);//input
   
    };
    
}
#endif
