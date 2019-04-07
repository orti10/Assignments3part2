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
      
        if(!this->sameUnit(p1)) throw "not the same family unit can not convert";
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num+unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
    }
    
	const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1){
	     if(!this->sameUnit(p1)) throw "not the same family unit can not convert";
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num-unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
	}
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& p1){
	  PhysicalNumber pn =(*this+p1);
      num =pn.num;
        return *this;
	}
	PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& p1){
        PhysicalNumber pn =(*this-p1);
        num =pn.num;
        return *this;	}
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
        num++;
	return *this;
    }
    PhysicalNumber PhysicalNumber::operator++(int){//i++
        PhysicalNumber pn(*this);
        num++;
         return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(){//--i
     num--;
     return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(int){//i--
     PhysicalNumber pn(*this);
     num--;
        
     return *this;
    }
    
   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    os << c.num << "[" << endings[c.u] << "]";
    return os ;

    }
  istream &ariel::operator>> (istream& is, PhysicalNumber& c){
	return is;
}

//private functions

 bool PhysicalNumber::sameUnit(const PhysicalNumber& other){ 
     //first family unit
     if((other.u >=0 && other.u<=2) && (this->u >=0 && this->u<=2)){
         return true;
     }
     //second family unit
     else if((other.u >=3 && other.u<=5) && (this->u >=3 && this->u<=5)){
         return true;
     }
     //third family unit
     else if((other.u >=6 && other.u<=5) && (this->u >=3 && this->u<=8)){
         return true;
     }
     else return false;
 }
double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right){
      if(!left.sameUnit(right)) throw "not the same family unit can not convert";
      switch (left.u){
            case KM:
            switch(right.u){                
                case M:
                return right.num*1000;
                break;
                
                case CM:
                return right.num*100000;
                break;
                default:
                throw "the values are not the same type";
            }
            break;
            case M:
            switch(right.u){
                
                case KM:
                return right.num*1000;
                break;
                
                case CM:
                return right.num*100;
                break;
                default:
                throw "the values are not the same type";
                
            }
            break;
            
            case CM:
            switch(right.u){
                case KM:
                return right.num/100000;
                break;
                
                case M:
                return right.num/100;
                break;

                default:
                throw "the values are not the same type";
            }
            break;

            case HOUR:
            switch(right.u){
                case MIN:
                return right.num/60;
                break;
                
                case SEC:
                return right.num/3600;
                break;
                default:
                throw "the values are not the same type";
            }
            break;
            case MIN:
            switch(right.u){
                
                case HOUR:
                return right.num*60;
                break;
                
                case SEC:
                return right.num/60;
                break;
                default:
                throw "the values are not the same type";
            }
            break;
            case SEC:
            switch(right.u){
                
                case HOUR:
                return right.num*3600;
                break;
                
                case MIN:
                return right.num*60;
                break;
                default:
                throw "the values are not the same type";
            }
            break;
            case TON:
            switch(right.u){
                case KG:
                return right.num*1000;
                break;
                
                case G:
                return right.num*1000000;
                break;

                default:
                throw "the values are not the same type";
            }
            break;
             case KG:
            switch(right.u){
                case TON:
                return right.num/1000;
                break;
                
                case G:
                return right.num*1000;
                break;
                default:
                throw "the values are not the same type";
            }
            break; 
            case G:
            switch(right.u){
                
                case KG:
                return right.num/1000;
                break;
                
                case TON:
                return right.num/1000000;
                break;
                default:
                throw "the values are not the same type";
            }
            break;
        }

    }

  

