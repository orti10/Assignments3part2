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
        if(this->sameUnit(p1)==true){////check if there is a reason to throw and exception
        
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num+unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
        }
        else throw runtime_error("not the same family unit can not convert18");
    }
    //A-B
	const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1){
	   if(this->sameUnit(p1)==true){ //check if there is a reason to throw and exception
        
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num-unit_Converter(*this,pn);
        return PhysicalNumber(new_value,u);
       }
       else throw runtime_error("not the same family unit can not convert19");
	}
    //A=A+B
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &p1){
      PhysicalNumber pn =(*this+p1); //using +operator we wrote
      this->num =pn.num;
     
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
        return PhysicalNumber(-num,u); //the num turns minus signed
    } 

    bool PhysicalNumber::operator>(const PhysicalNumber &other){
        if(sameUnit(other)==false) throw runtime_error("not the same family unit can not convert40");//check if there is a reason to throw and exception
        
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return (this->num)>ans; 
        
         return false;
        }
    }

    bool PhysicalNumber::operator<(const PhysicalNumber& other){
        if(sameUnit(other)==false) throw runtime_error("not the same family unit can not convert45");//check if there is a reason to throw and exception
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return (this->num)<ans;
        
         return false;
        }
    }
    bool PhysicalNumber::operator>=(const PhysicalNumber& other){
        if(sameUnit(other)==false)throw runtime_error("not the same family unit can not convert44");//check if there is a reason to throw and exception
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1>p2 && p1==p2){
                return true;
            }
            return false;
        }
        
    }
    bool PhysicalNumber::operator<=(const PhysicalNumber& other){
        if(sameUnit(other)==false) throw runtime_error("not the same family unit can not convert43");//check if there is a reason to throw and exception
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1<p2 && p1==p2){
                return true;
            }
            return false;
        }
    }
    bool PhysicalNumber::operator==(const PhysicalNumber& other){
        if(sameUnit(other)==false) throw runtime_error("not the same family unit can not convert41");//check if there is a reason to throw and exception
        else{
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1>p2 || p1<p2){
                return false;
            }
            return true;
        }
        
    }
    bool PhysicalNumber::operator!=(const PhysicalNumber& other){ //using == operator
       if(*this==other) return false;
       return true;
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
    PhysicalNumber PhysicalNumber::operator--(){//--i first subtracting and then print
        num--;
        return *this;
    }
    //A--
    PhysicalNumber PhysicalNumber::operator--(int){//i-- firts print and then subtracting
        PhysicalNumber pn(*this);
        num--;
        
     return *this;
    }
    
   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    os << c.num << "[" << endings[c.u] << "]";
    return os ;

    }
//   istream &ariel::operator>> (istream& is, PhysicalNumber& c){
// 	return is;
// }

std::istream& ariel::operator>>(istream& is, PhysicalNumber& pn) {
    string str;
    long double d;
    ios::pos_type sp = is.tellg();
    if(!(is >> d) || !(checkInputUnit(is, pn))) {
        auto es = is.rdstate();
        is.clear();
        is.seekg(sp);
        is.clear(es);
    }
    else {
        pn.setData(d);
    }
    
    return is;
}
void PhysicalNumber::setData(double d) { num = d; }
void PhysicalNumber::setUnit(Unit u) { u = u; }
istream& ariel::checkInputUnit(istream& is, PhysicalNumber& pn) {
    string s;
    int i, j;
    is >> s;
    i = s.find('[');
    j = s.find(']');
    if(!is) { return is; }
    if((i == -1) || (j == -1)) { 
        is.setstate(ios::failbit);
        return is; 
    }
    s = s.substr(i+1, j-1);
    if(s.compare("km") == 0) { pn.setUnit(Unit::KM); }
    else if(s.compare("m") == 0) { pn.setUnit(Unit::M); }
    else if(s.compare("cm") == 0) { pn.setUnit(Unit::M); }
    else if(s.compare("ton") == 0) { pn.setUnit(Unit::TON); }
    else if(s.compare("kg") == 0) { pn.setUnit(Unit::KG); }
    else if(s.compare("g") == 0) { pn.setUnit(Unit::G); }
    else if(s.compare("hour") == 0) { pn.setUnit(Unit::HOUR); }
    else if(s.compare("min") == 0) { pn.setUnit(Unit::MIN); }
    else if(s.compare("sec") == 0) { pn.setUnit(Unit::SEC); }
    else{ is.setstate(ios:: failbit); }

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
                else if((other.u >=6 && other.u<=8) && (this->u >=6 && this->u<=8)){
        
                         return true;
     }
     else return false;
}

//checking if the given Physical Numbers can be convert
double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right){
      if(left.sameUnit(right)==false) {
          throw runtime_error("not the same family unit can not convert1");
      }
      else{
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
                throw runtime_error("not the same family unit can not convert2");
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
               throw runtime_error("not the same family unit can not convert3");
                
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
                throw runtime_error("not the same family unit can not convert4");
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
                throw runtime_error("not the same family unit can not convert5");
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
                throw runtime_error("not the same family unit can not convert6");
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
               throw runtime_error("not the same family unit can not convert7");
            }
            break;
            case TON:
            switch(right.u){
               
                case TON:
                return right.num;
                break;  
               
                case KG:
                return right.num/1000;//was*
                break;
                
                case G:
                return right.num/1000000;//was*
                break;

                default:
                throw runtime_error("not the same family unit can not convert8");
            }
            break;
            case KG:
            switch(right.u){
                
                case KG:
                return right.num;
                break;  
                
                case TON:
                return right.num*1000;
                break;
                
                case G:
                return right.num/1000;
                break;
                
                default:
                throw runtime_error("not the same family unit can not convert9");
            }
            break; 
            case G:
            switch(right.u){
                
                case G:
                return right.num;
                break;  
                
                case KG:
                return right.num*1000;
                break;
                
                case TON:
                return right.num/1000000;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert10");
            }
            break;
        }   
    }
}
     