#include "PhysicalNumber.h"
#include <iostream>
#include<exception>
#include <math.h> 
using namespace std;
using namespace ariel;

    //constructors
    PhysicalNumber::PhysicalNumber(double number,Unit unit):num(number),u(unit){}
    PhysicalNumber::PhysicalNumber(const PhysicalNumber& pn):num(pn.num),u(pn.u){}
    
    //A+B
    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p1){
        if(!this->sameUnit(p1)) throw "not the same family unit can not convert";
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num+unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
    }
    //A-B
	const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1){
	     if(!this->sameUnit(p1)) throw "not the same family unit can not convert";
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num-unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
	}
    //A=A+B
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &p1){
	  PhysicalNumber pn =(*this+p1); //using +operator we wrote
      num =pn.num;
      cout<<"pn is"<<pn.u <<"this is"<<this->u <<"p1 is"<<p1.u;
        return *this;
	}
    //A=A-B
	PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &p1){
        PhysicalNumber pn =(*this-p1);//using -operator we wrote
        num =pn.num;
        return *this;	
    }
    //+A
    PhysicalNumber PhysicalNumber::operator+(){// Unari
        return *this; //stay the same
    }
    //-A 
	PhysicalNumber PhysicalNumber::operator-(){// Unari
        return PhysicalNumber(-num,u); //the num turns minus
    } 

    bool PhysicalNumber::operator> (const PhysicalNumber &other){
        if(!sameUnit(other)) throw "not the same family unit can not comper";
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return ans>this->num;
        }
    }

    bool PhysicalNumber::operator< (const PhysicalNumber& other){
        if(!sameUnit(other)) throw "not the same family unit can not comper";
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return ans<this->num;
        }
    }
    bool PhysicalNumber::operator>= (const PhysicalNumber& other){
        if(!sameUnit(other)) throw "not the same family unit can not comper";
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1>p2 && p1==p2){
                return false;
            }
            return true;
        }
    }
    bool PhysicalNumber::operator<= (const PhysicalNumber& other){
        if(!sameUnit(other)) throw "not the same family unit can not comper";
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1<p2 && p1==p2){
                return false;
            }
            return true;
        }
    }
    bool PhysicalNumber::operator== (const PhysicalNumber& other){
        if(!sameUnit(other)) throw "not the same family unit can not comper";
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1>p2 || p1<p2){
                return false;
            }
            return true;
        }
    }
    bool PhysicalNumber::operator!= (const PhysicalNumber& other){
       return (*this==other);
    }
    //++A
    PhysicalNumber PhysicalNumber::operator++(){//++i first add and then print
        num++;
	    return *this;
    }
    //++A
    PhysicalNumber PhysicalNumber::operator++(int){//i++ first print and then add
        PhysicalNumber pn(*this);
        num++;
        return *this;
    }
    //--A
    PhysicalNumber PhysicalNumber::operator--(){//--i
        num--;
        return *this;
    }
    //A--
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

//private functions:

//checking if the given units are from the same "family" [mass,time,lenght]
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

//checking if the given Physical Numbers can be convert
double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right){
      if(!left.sameUnit(right)) throw "not the same family unit can not convert";
      switch (left.u){
            case KM:
            switch(right.u){ 
                case KM:
                return right.num;
                break;               
               
                case M:
                return right.num/1000;//was*
                break;
                
                case CM:
                return right.num/100000;//was*
                break;
               
                default:
                throw "the values are not the same type";
            }
            break;
            case M:
            switch(right.u){
                
                case M:
                return right.num;
                break;  

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
                
                case CM:
                return right.num;
                break;  

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
                
                case HOUR:
                return right.num;
                break;  
               
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
                
                case MIN:
                return right.num;
                break;  
               
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
                
                case SEC:
                return right.num;
                break;  
                
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
               
                case TON:
                return right.num;
                break;  
               
                case KG:
                cout<<"int ton->kg";
                return right.num/1000;//was*
                break;
                
                case G:
                return right.num/1000000;//was*
                break;

                default:
                throw "the values are not the same type";
            }
            break;
            case KG:
            switch(right.u){
                
                case KG:
                return right.num;
                break;  
                
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
                
                case G:
                return right.num;
                break;  
                
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
