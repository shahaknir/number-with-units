//
// Created by shahak on 11/06/2021.
//

#include "NumberWithUnits.hpp"
#include <iostream>

namespace ariel{


    /**
     * Constructor getting a double const and string
     * @param x - the amount of the unit
     * @param str - name of unit
     */
    NumberWithUnits::NumberWithUnits(const double &x, const string &str) {

    }

    /**
     * get a file and extract the units data into a map
     * @param ifstream1
     */
    void NumberWithUnits::read_units(ifstream &ifstream1) {

    }

    /**
     * @param numberWithUnits1
     * @param numberWithUnits2
     * @return 1 - if the first object is bigger, 0 - if they ar equal, -1 - if the first object is smaller
     */
    int compare_units(const NumberWithUnits &numberWithUnits1, const NumberWithUnits &numberWithUnits2) {
        return 0;
    }

    /**
     * input / output methods - get or push an object of this class
     * @param ostream1 / istream1
     * @param numberWithUnits
     * @return
     */
    ostream &operator<<(ostream &ostream1, const NumberWithUnits &numberWithUnits) {
        return ostream1;
    }

    istream &operator>>(istream &istream1, NumberWithUnits &numberWithUnits1) {
        return istream1;
    }

    /**
     * Overloading the operator (-)
     * @func1 - (a - b)
     * @func2 - (a - 5.5)
     * @func3 - (5.5 - a)
     * @func4 -     (- a)
     */
    NumberWithUnits operator-(const NumberWithUnits &numberWithUnits1, const NumberWithUnits &numberWithUnits2) {
        return NumberWithUnits();
    }

    NumberWithUnits operator-(const NumberWithUnits &numberWithUnits, double x) {
        return NumberWithUnits();
    }

    NumberWithUnits operator-(double x, const NumberWithUnits &numberWithUnits) {
        return NumberWithUnits();
    }

    NumberWithUnits operator-(const NumberWithUnits &numberWithUnits) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (+)
     * @func1 - (a + b)
     * @func2 - (a + 5.5)
     * @func3 - (5.5 + a)
     * @func4 -     (+ a)
     */
    NumberWithUnits operator+(const NumberWithUnits &numberWithUnits1, const NumberWithUnits &numberWithUnits2) {
        return NumberWithUnits();
    }

    NumberWithUnits operator+(const NumberWithUnits &numberWithUnits1, double x) {
        return NumberWithUnits();
    }

    NumberWithUnits operator+(double x, const NumberWithUnits &numberWithUnits) {
        return NumberWithUnits();
    }

    NumberWithUnits operator+(const NumberWithUnits &numberWithUnits) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (*)
     * @func1 - (a * b)
     * @func2 - (a * 5.5)
     * @func3 - (5.5 * a)
     */
    NumberWithUnits operator*(const NumberWithUnits &numberWithUnits1, const NumberWithUnits &numberWithUnits2) {
        return NumberWithUnits();
    }

    NumberWithUnits operator*(const NumberWithUnits &numberWithUnits, double x) {
        return NumberWithUnits();
    }

    NumberWithUnits operator*(double x, const NumberWithUnits &numberWithUnits) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (/)
     * @func1 - (a / b)
     * @func2 - (a / 5.5)
     * @func3 - (5.5 / a)
     */
    NumberWithUnits operator/(const NumberWithUnits &numberWithUnits1, const NumberWithUnits &numberWithUnits2) {
        return NumberWithUnits();
    }

    NumberWithUnits operator/(const NumberWithUnits &numberWithUnits, double x) {
        return NumberWithUnits();
    }

    NumberWithUnits operator/(double, const NumberWithUnits &) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (+=)
     * @func1 - (a += b)
     * @func2 - (a += 5.5)
     * @func3 - (5.5 += a)
     */
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num) {
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator+=(const double &num) {
        return *this;
    }

    NumberWithUnits operator+=(double, NumberWithUnits &num) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (-=)
     * @func1 - (a -= b)
     * @func2 - (a -= 5.5)
     * @func3 - (5.5 -= a)
     */
    NumberWithUnits operator-=(double, NumberWithUnits &num) {
        return NumberWithUnits();
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num) {
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator-=(const double &num) {
        return *this;
    }

    /**
     * Overloading the operator (*=)
     * @func1 - (a *= b)
     * @func2 - (a *= 5.5)
     * @func3 - (5.5 *= a)
     */
    NumberWithUnits &NumberWithUnits::operator*=(const NumberWithUnits &num) {
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator*=(const double &num) {
        return *this;
    }

    NumberWithUnits operator*=(double x, NumberWithUnits &num) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (/=)
     * @func1 - (a /= b)
     * @func2 - (a /= 5.5)
     * @func3 - (5.5 /= a)
     */
    NumberWithUnits &NumberWithUnits::operator/=(const NumberWithUnits &num) {
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator/=(const double &num) {
        return *this;
    }

    NumberWithUnits operator/=(double x, NumberWithUnits &num) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (==)
     * @func1 - (a == b)
     * @func2 - (a == 5.5)
     * @func3 - (5.5 == a)
     */
    bool operator==(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator==(double x, const NumberWithUnits &num) {
        return false;
    }

    bool operator==(const NumberWithUnits &num, double x) {
        return false;
    }

    /**
     * Overloading the operator (!=)
     * @func1 - (a != b)
     * @func2 - (a != 5.5)
     * @func3 - (5.5 != a)
     */
    bool operator!=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator!=(const NumberWithUnits &num, double x) {
        return false;
    }

    bool operator!=(double x, const NumberWithUnits &num) {
        return false;
    }

    /**
     * Overloading the operator (<)
     * @func1 - (a < b)
     * @func2 - (a < 5.5)
     * @func3 - (5.5 < a)
     */
    bool operator<(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator<(const NumberWithUnits &num, double x) {
        return false;
    }

    bool operator<(double x, const NumberWithUnits &num) {
        return false;
    }


    /**
     * Overloading the operator (>)
     * @func1 - (a > b)
     * @func2 - (a > 5.5)
     * @func3 - (5.5 > a)
     */
    bool operator>(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator>(const NumberWithUnits &num, double x) {
        return false;
    }

    bool operator>(double x, const NumberWithUnits &num) {
        return false;
    }

    /**
     * Overloading the operator (>=)
     * @func1 - (a >= b)
     * @func2 - (a >= 5.5)
     * @func3 - (5.5 >= a)
     */
    bool operator>=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator>=(const NumberWithUnits &num, double x) {
        return false;
    }

    bool operator>=(double x, const NumberWithUnits &num) {
        return false;
    }

    /**
     * Overloading the operator (<=)
     * @func1 - (a <= b)
     * @func2 - (a <= 5.5)
     * @func3 - (5.5 <= a)
     */
    bool operator<=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        return false;
    }

    bool operator<=(const NumberWithUnits &, double x) {
        return false;
    }

    bool operator<=(double x, const NumberWithUnits &num) {
        return false;
    }

    /**
     * Overloading the operator (++)
     * @func1 - (a++)
     * @func2 - (++a)
     */
    NumberWithUnits &NumberWithUnits::operator++() {
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int) {
        return NumberWithUnits();
    }

    /**
     * Overloading the operator (++)
     * @func1 - (a--)
     * @func2 - (--a)
     */
    NumberWithUnits &NumberWithUnits::operator--() {
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator--(int) {
        return NumberWithUnits();
    }


}