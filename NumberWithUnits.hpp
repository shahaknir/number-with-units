//
// Created by shahak on 10/06/2021.
//

#ifndef EX3_PA_NUMBERWITHUNITS_HPP
#define EX3_PA_NUMBERWITHUNITS_HPP

#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>


using namespace std;
namespace ariel {
    class NumberWithUnits{
    private:
        string unit_name;
        double unit_quantity;


    public:
        /**
         * empty constructor
        */
        NumberWithUnits(){
            this->unit_name = "km";
            this->unit_quantity = 1;
        }

        /**
         * Constructor getting a double const and string
         * @param x - the amount of the unit
         * @param str - name of unit
         */
        NumberWithUnits(const double& x,const string& str);

        /**
         * Destructor - Use to clean unused memory, when the object about to die
         */
        ~NumberWithUnits()= default;

        /**
         * get a file and extract the units data into a map
         * @param ifstream1
         */
        static void read_units(ifstream& ifstream1);

        /**
         * @param numberWithUnits1
         * @param numberWithUnits2
         * @return 1 - if the first object is bigger, 0 - if they ar equal, -1 - if the first object is smaller
         */
        friend int compare_units(const NumberWithUnits& numberWithUnits1, const NumberWithUnits&numberWithUnits2);

        /**
         * input / output methods - get or push an object of this class
         * @param ostream1 / istream1
         * @param numberWithUnits
         * @return
         */
        friend ostream& operator<<(ostream& ostream1, const NumberWithUnits& numberWithUnits);
        friend istream& operator>>(istream& istream1, NumberWithUnits& numberWithUnits);

        /**
         * Overloading the operator (-)
         * @func1 - (a - b)
         * @func2 - (a - 5.5)
         * @func3 - (5.5 - a)
         * @func4 -     (- a)
         */
        friend NumberWithUnits operator-(const NumberWithUnits& numberWithUnits1 ,const NumberWithUnits& numberWithUnits2);
        friend NumberWithUnits operator-(const NumberWithUnits& numberWithUnits, double x);
        friend NumberWithUnits operator-(double x ,const NumberWithUnits& numberWithUnits);
        friend NumberWithUnits operator-(const NumberWithUnits& numberWithUnits);

        /**
         * Overloading the operator (+)
         * @func1 - (a + b)
         * @func2 - (a + 5.5)
         * @func3 - (5.5 + a)
         * @func4 -     (+ a)
         */
        friend NumberWithUnits operator+(const NumberWithUnits& numberWithUnits1,const NumberWithUnits& numberWithUnits2);
        friend NumberWithUnits operator+(const NumberWithUnits& numberWithUnits1, double x);
        friend NumberWithUnits operator+(double x,const NumberWithUnits& numberWithUnits);
        friend NumberWithUnits operator+(const NumberWithUnits& numberWithUnits);

        /**
         * Overloading the operator (*)
         * @func1 - (a * b)
         * @func2 - (a * 5.5)
         * @func3 - (5.5 * a)
         */
        friend NumberWithUnits operator*(const NumberWithUnits& numberWithUnits1,const NumberWithUnits& numberWithUnits2);
        friend NumberWithUnits operator*(const NumberWithUnits& numberWithUnits, double x);
        friend NumberWithUnits operator*(double x,const NumberWithUnits& numberWithUnits);

        /**
        * Overloading the operator (/)
        * @func1 - (a / b)
        * @func2 - (a / 5.5)
        * @func3 - (5.5 / a)
        */
        friend NumberWithUnits operator/(const NumberWithUnits& numberWithUnits1,const NumberWithUnits& numberWithUnits2);
        friend NumberWithUnits operator/(const NumberWithUnits& numberWithUnits, double x);
        friend NumberWithUnits operator/( double ,const NumberWithUnits&);

        /**
         * Overloading the operator (+=)
         * @func1 - (a += b)
         * @func2 - (a += 5.5)
         * @func3 - (5.5 += a)
         */
        NumberWithUnits &operator+=(const NumberWithUnits &num);
        NumberWithUnits &operator+=(const double &num);
        friend NumberWithUnits operator+=( double , NumberWithUnits&num);

        /**
         * Overloading the operator (-=)
         * @func1 - (a -= b)
         * @func2 - (a -= 5.5)
         * @func3 - (5.5 -= a)
         */
        friend NumberWithUnits operator-=(double , NumberWithUnits&num);
        NumberWithUnits &operator-=(const NumberWithUnits &num);
        NumberWithUnits &operator-=(const double &num);

        /**
        * Overloading the operator (*=)
        * @func1 - (a *= b)
        * @func2 - (a *= 5.5)
        * @func3 - (5.5 *= a)
        */
        NumberWithUnits &operator*=(const NumberWithUnits &num);
        NumberWithUnits &operator*=(const double &num);
        friend NumberWithUnits operator*=(double x, NumberWithUnits&num);

        /**
        * Overloading the operator (/=)
        * @func1 - (a /= b)
        * @func2 - (a /= 5.5)
        * @func3 - (5.5 /= a)
        */
        NumberWithUnits &operator/=(const NumberWithUnits &num);
        NumberWithUnits &operator/=(const double &num);
        friend NumberWithUnits operator/=(double x, NumberWithUnits&num);

        /**
        * Overloading the operator (==)
        * @func1 - (a == b)
        * @func2 - (a == 5.5)
        * @func3 - (5.5 == a)
        */
        friend bool operator==(const NumberWithUnits& num1,const NumberWithUnits& num2);
        friend bool operator==(double x,const NumberWithUnits& num);
        friend bool operator==(const NumberWithUnits& num, double x);

        /**
         * Overloading the operator (!=)
         * @func1 - (a != b)
         * @func2 - (a != 5.5)
         * @func3 - (5.5 != a)
         */
        friend bool operator!=(const NumberWithUnits& num1,const NumberWithUnits&num2);
        friend bool operator!=(const NumberWithUnits& num, double x);
        friend bool operator!=( double x,const NumberWithUnits&num);

        /**
         * Overloading the operator (<)
         * @func1 - (a < b)
         * @func2 - (a < 5.5)
         * @func3 - (5.5 < a)
         */
        friend bool operator<(const NumberWithUnits& num1, const NumberWithUnits& num2);
        friend bool operator<(const NumberWithUnits& num, double x);
        friend bool operator<(double x,const NumberWithUnits& num);

        /**
         * Overloading the operator (>)
         * @func1 - (a > b)
         * @func2 - (a > 5.5)
         * @func3 - (5.5 > a)
         */
        friend bool operator>(const NumberWithUnits& num1,const NumberWithUnits& num2);
        friend bool operator>(const NumberWithUnits& num, double x);
        friend bool operator>(double x,const NumberWithUnits& num);

        /**
         * Overloading the operator (>=)
         * @func1 - (a >= b)
         * @func2 - (a >= 5.5)
         * @func3 - (5.5 >= a)
         */
        friend bool operator>=(const NumberWithUnits& num1, const NumberWithUnits& num2);
        friend bool operator>=(const NumberWithUnits& num, double x);
        friend bool operator>=(double x,const NumberWithUnits& num);

        /**
         * Overloading the operator (<=)
         * @func1 - (a <= b)
         * @func2 - (a <= 5.5)
         * @func3 - (5.5 <= a)
         */
        friend bool operator<=(const NumberWithUnits& num1,const NumberWithUnits& num2);
        friend bool operator<=(const NumberWithUnits& , double x);
        friend bool operator<=(double x,const NumberWithUnits& num);

        /**
         * Overloading the operator (++)
         * @func1 - (a++)
         * @func2 - (++a)
         */
        NumberWithUnits& operator++();
        NumberWithUnits operator++(int);

         /**
          * Overloading the operator (++)
          * @func1 - (a--)
          * @func2 - (--a)
          */
        NumberWithUnits& operator--();
        NumberWithUnits operator--(int);


    };
}


#endif //EX3_PA_NUMBERWITHUNITS_HPP
