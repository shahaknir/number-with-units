#include "NumberWithUnits.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

namespace ariel{

    void read_units(ifstream& filetxt){
        // return filetxt;
    }
    NumberWithUnits::NumberWithUnits():t(0), temp{""} {}
    NumberWithUnits::NumberWithUnits(int num, string a){
        // this->t = num;
        // this->temp = a;
    }


    // Numeric operators
    NumberWithUnits operator+(NumberWithUnits& a, const NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator+=(NumberWithUnits& a, const NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator-(NumberWithUnits& a, const NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator-=(NumberWithUnits& a, const NumberWithUnits b){
        return a;
    }
    NumberWithUnits operator*(double other, NumberWithUnits& a){
        return a;
    }
    // NumberWithUnits operator*(int other, NumberWithUnits& a){
        // return a;
    // }
                    
    
    NumberWithUnits operator+(unsigned int a, NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator+=(unsigned int a, NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator-(unsigned int a, NumberWithUnits b){
        return b;
    }
    NumberWithUnits operator-=(unsigned int a, NumberWithUnits b){
        return b;
    }            

    // ++ --
    NumberWithUnits operator++(NumberWithUnits& a){
        return a;
    }
    NumberWithUnits operator--(NumberWithUnits& a){
        return a;
    }

    // Uneric + & -
    const NumberWithUnits operator+(NumberWithUnits& a){
        return a;
    }
    const NumberWithUnits operator-(NumberWithUnits& a){
        return a;
    }
            
    // Comperation Operator Overload
    bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
       

    // Streamming Operator Overload        
    ostream& operator>>(ostream& input, const NumberWithUnits& num){
        return input;
    }
    ostream& operator<<(ostream& output, const NumberWithUnits& num){
        return output;
    }
    istringstream& operator>>(istringstream& input, const NumberWithUnits& num){
        return input;
    }
    istringstream& operator<<(istringstream& output, const NumberWithUnits& num){
        return output;
    }

}