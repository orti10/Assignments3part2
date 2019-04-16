#include "PhysicalNumber.h"
#include <iostream>
#include<exception>
#include <math.h> 
using namespace std;
using namespace ariel;

    //constructors
    PhysicalNumber::PhysicalNumber(const double number,const Unit unit){
         this->u=unit;
        this->num=number;
    }
    PhysicalNumber::PhysicalNumber(const PhysicalNumber& pn){
        this->u=pn.u;
        this->num=pn.num;
    }
    
    //A+B
     PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p1)const{
        //check if there is a reason to throw and exception
        PhysicalNumber thispn =PhysicalNumber(this->num,this->u);
        if(thispn.sameUnit(p1)==false) throw runtime_error("not the same family unit can not convert18");
        
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= thispn.num + unit_Converter(thispn,pn);
        return PhysicalNumber(new_value,u);
        
    }
    //A-B
	 PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1)const{
        //check if there is a reason to throw and exception
	    PhysicalNumber thispn =PhysicalNumber(this->num,this->u);

       if(thispn.sameUnit(p1)==false) throw runtime_error("not the same family unit can not convert19");
        
        PhysicalNumber pn =PhysicalNumber(p1.num,p1.u);
        double new_value= this->num-1*(unit_Converter(thispn,pn));
      
        return PhysicalNumber(new_value,u);
       
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
        
        this->num =pn.num;
        
        return *this;	
    }
    PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& p1){
        this->num = p1.num;
        this->u =p1.u;
        return *this;
    }

    //+A
     PhysicalNumber PhysicalNumber::operator+()const{// Unari
        if(this->num <0){
            return PhysicalNumber(num*(-1),u);
        }
        else
        return *this;
    }
    //-A 
	 PhysicalNumber PhysicalNumber::operator-()const{// Unari

            return PhysicalNumber(num*(-1),u); //the num turns minus signed
    } 

    bool PhysicalNumber::operator>(const PhysicalNumber &other){
        //check if there is a reason to throw and exception
        if(this->sameUnit(other)==false) throw runtime_error("not the same family unit can not convert40");        
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return (this->num>ans) ;         
    }

    bool PhysicalNumber::operator<(const PhysicalNumber& other){
        //check if there is a reason to throw and exception
        if(this->sameUnit(other)==false) throw runtime_error("not the same family unit can not convert45");
        
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            double ans=unit_Converter(p1,p2);
            return (this->num<ans);
        
    }
    bool PhysicalNumber::operator>=(const PhysicalNumber& other){
        //check if there is a reason to throw and exception
        if(this->sameUnit(other)==false)throw runtime_error("not the same family unit can not convert44");
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1>p2 || p1==p2){
                return true;
            }
            else
            return false;
     
    }
    bool PhysicalNumber::operator<=(const PhysicalNumber& other){
        //check if there is a reason to throw and exception
        
        if(this->sameUnit(other)==false) throw runtime_error("not the same family unit can not convert43");
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(other.num,other.u);
            if(p1 == p2 || p1<p2){
               return true;
            }
            else
            return false;
        
    }
    bool PhysicalNumber::operator==(const PhysicalNumber& num2){
        //check if there is a reason to throw and exception
        if(this->sameUnit(num2)==false) throw runtime_error("not the same family unit can not convert41");
        
            PhysicalNumber p1=PhysicalNumber(this->num,this->u);
            PhysicalNumber p2=PhysicalNumber(num2.num,num2.u);
            if(p1>p2 || p1<p2){
                return false;
            }
            else
            return true;
        
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
        return pn;
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
        
     return pn;
    }
    
   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    PhysicalNumber pn (c.num,c.u);
    string str;
    switch (pn.u) {
        case Unit::KM :
            str = "km";
            break;
        case Unit::M :
            str = "m";
            break;
        case Unit::CM :
            str = "cm";
            break;
        case Unit::HOUR :
            str = "hour";
            break;
        case Unit::MIN :
            str = "min";
            break;
        case Unit::SEC :
            str = "sec";
            break;
        case Unit::TON :
            str = "ton";
            break;
        case Unit::KG :
            str = "kg";
            break;
        case Unit::G :
            str = "g";
            break;
    }
    return os << pn.num << "[" << str << "]";
    }


istream& ariel::operator>>(istream& is, PhysicalNumber& pn) {
    string input;

// remember place for rewinding
std::ios::pos_type startPosition = is.tellg();

is >> input;

Unit new_type; // Answers
double new_Value; // Ansers

int f_index = input.find('[');
int l_index = input.find(']');

if(f_index == -1 || l_index == -1 || f_index >= l_index) 
{
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

std::string numbers = input.substr(0,f_index);
std::string s_type = input.substr(f_index+1,l_index - f_index - 1 );

try
{
    new_Value = stod(numbers);   
}
catch(std::exception& e)
{
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

if( s_type.compare("km") == 0 ) new_type = Unit::KM; 
else if( s_type.compare("m") == 0 ) new_type = Unit::M; 
else if( s_type.compare("cm") == 0 ) new_type = Unit::CM; 

else if( s_type.compare("ton") == 0 ) new_type = Unit::TON; 
else if( s_type.compare("kg") == 0 ) new_type = Unit::KG; 
else if( s_type.compare("g") == 0 ) new_type = Unit::G; 

else if( s_type.compare("hour") == 0 ) new_type = Unit::HOUR; 
else if( s_type.compare("min") == 0 ) new_type = Unit::MIN; 
else if( s_type.compare("sec") == 0 ) new_type = Unit::SEC;
else {
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

pn.u = new_type;
pn.num = new_Value;
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
double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right)const{
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
                return right.num/1000;
                break;
                
                case CM:
                return right.num/100000;
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
                return right.num/100;
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
                return right.num*100000;
                break;
                
                case M:
                return right.num*100;
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
                return right.num/1000;
                break;
                
                case G:
                return right.num/1000000;
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
                return right.num*1000000;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert10");
            }
            break;
        }   
    }
}
     