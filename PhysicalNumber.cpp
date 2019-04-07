#include "PhysicalNumber.h"
#include <iostream>
#include<exception>
#include <math.h> 
using namespace std;
using namespace ariel;


    PhysicalNumber::PhysicalNumber(double num,Unit u){
         this->num=num;
         this->u=u;
     }
    PhysicalNumber::PhysicalNumber(const PhysicalNumber& pn){
        this->num=pn.num;
        this->u=pn.u;
    }

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p1){
         double value=num;
         return PhysicalNumber(value,u);
    }
    
	const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1){
	      double value=num;
         return PhysicalNumber(value,u);
	}
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& p1){
	    return *this;
	}
	PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& p1){
	    return *this;
	}
    PhysicalNumber PhysicalNumber::operator+(){
        return *this;
    } // Unari
	PhysicalNumber PhysicalNumber::operator-(){
        return *this;
    } // Unari

    bool PhysicalNumber::operator> (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator< (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator>= (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator<= (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator== (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator!= (const PhysicalNumber& other){
        return false;
    }
    
    PhysicalNumber PhysicalNumber::operator++(){//++i first add and then print
        //++*this.num; //better
        //return PhysicalNumber(*this.num,*this.u);
	return *this;
    }
    PhysicalNumber PhysicalNumber::operator++(int){//i++
        PhysicalNumber pn(*this);
        //++*this.num;
        //return PhysicalNumber(pn.num,pn.u);//first print and then add
    	 return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(){//--i
     //return PhysicalNumber(*this.num-1,*this.u);
    return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(int){//i--
     return *this;
    }
    
   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    
    return os ;

    }
  istream &ariel::operator>> (istream& is, PhysicalNumber& c){
	return is;
}

