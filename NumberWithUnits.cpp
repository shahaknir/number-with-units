#include "NumberWithUnits.hpp"

namespace ariel{

    char read_units(char a){
        return ' ';
    }
    NumberWithUnits::NumberWithUnits():t(0), temp{""} {}
    NumberWithUnits::NumberWithUnits(int num, string const& a){
        // this->t = num;
        // this->temp = a;
    }


    // Numeric operators
    NumberWithUnits operator+(const NumberWithUnits& a, NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator+=(const NumberWithUnits& a, NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator-(const NumberWithUnits& a, NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator-=(const NumberWithUnits& a, NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator*(const NumberWithUnits& a, double other){
        return a;
    }
            
    
    NumberWithUnits operator+(unsigned int a, const NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator+=(unsigned int a, const NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator-(unsigned int a, const NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator-=(unsigned int a, const NumberWithUnits b){
        return b;
    }            

    // ++ --
    NumberWithUnits operator++(const NumberWithUnits& a){
        return a;
        }
    NumberWithUnits operator--(const NumberWithUnits& a){
        return a;
        }

    // Uneric + & -
    const NumberWithUnits operator+(const NumberWithUnits& a){
        return a;
        }
    const NumberWithUnits operator-(const NumberWithUnits& a){
        return a;
        }
            
    // Comperation Operator Overload
    bool operator==(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
    bool operator!=(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
    bool operator>(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
    bool operator>=(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
    bool operator<=(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
    bool operator<(const NumberWithUnits& n1, NumberWithUnits& n2){
        return true;
    }
       
    // Streamming Operator Overload        
    ostream& operator>>(ostream& input, const NumberWithUnits& num){
        return input;
    }
    ostream& operator<<(ostream& output, const NumberWithUnits& num){
        return output;
    }





}