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

  
    double unit_Converter(PhysicalNumber& p1 ,PhysicalNumber& p2)const;
    friend istream& checkInputUnit(istream& is, PhysicalNumber& pn);
    bool sameUnit(const PhysicalNumber& p1);

    public:
    PhysicalNumber(const double number,const Unit unit);//consts 2
    PhysicalNumber(const PhysicalNumber& pn);
    void setData(double d);
    void setUnit(Unit u);

    PhysicalNumber operator+(const PhysicalNumber& p1)const; 
	PhysicalNumber operator-(const PhysicalNumber& p1)const;
	PhysicalNumber& operator+=(const PhysicalNumber& p1);
	PhysicalNumber& operator-=(const PhysicalNumber& p1);
	PhysicalNumber& operator=(const PhysicalNumber& p1);

    PhysicalNumber operator+()const; // Unari
	PhysicalNumber operator-()const; // Unari

    bool operator> (const PhysicalNumber& p1) ;
    bool operator< (const PhysicalNumber& p1) ;
    bool operator>= (const PhysicalNumber& p1) ;
    bool operator<= (const PhysicalNumber& p1) ;
    bool operator== (const PhysicalNumber& p1) ;
    bool operator!= (const PhysicalNumber& p1) ;

    PhysicalNumber operator++();//++i
    PhysicalNumber operator++(int i);//i++
    PhysicalNumber operator--();//--i
    PhysicalNumber operator--(int i);//i--
    
    
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);//output
    friend istream& operator>> (istream& is, PhysicalNumber& c);//input
   
    };
     ostream& operator<< (ostream& os, const PhysicalNumber& c);//output
     istream& operator>> (istream& is, PhysicalNumber& c);//input
}
#endif
