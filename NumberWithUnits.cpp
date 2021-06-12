//
// Created by shahak on 11/06/2021.
// Some of the functions contains internet based solutions

#include "NumberWithUnits.hpp"
#include <iostream>
constexpr double NEPSILON = -0.000000001;
constexpr double EPSILON = 0.0001;


namespace ariel{
    map<string, map<string, double>> units_map;
    map<string, uint> units_dictionary;

    /**
     * Constructor getting a double const and string
     * @param x - the amount of the unit
     * @param str - name of unit
     */
    NumberWithUnits::NumberWithUnits(const double &x, const string &str) {
        this->unit_quantity = x;
        this->unit_name = str;
    }

    /**
     * get a file and extract the units data into a map
     * @param ifstream1
     */
    void NumberWithUnits::read_units(ifstream &units_file) {
        string unit_name_1;
        string unit_name_2;
        string equals_symbol;
        double num1 = NEPSILON; double num2 = NEPSILON;
        while (units_file >> num1 >> unit_name_1 >> equals_symbol >> num2 >> unit_name_2){
            if(num1 == 1 && equals_symbol == "=" && num2 > 0){
                units_map[unit_name_2][unit_name_1] = 1 / num2;
                units_map[unit_name_1][unit_name_2] = num2;
                units_dictionary[unit_name_1] = 1;
                units_dictionary[unit_name_2] = 1;
            }else{
                throw invalid_argument{"Error: unit file convertion has FAILED!\n"};
            }
        }
    }

    /**
     * converting one number with units to another
     * @param unit_name_1
     * @param unit_name_2
     * @param val
     * @return unit converted quantity
     */
    double convert_unit2unit(const string& unit_name_1, const string& unit_name_2, const double val){
        if(unit_name_1 == unit_name_2) {

            return val;
        }
        if(units_map.count(unit_name_1) > 0 && units_map.at(unit_name_1).count(unit_name_2) > 0){
            return units_map.at(unit_name_1).at(unit_name_2) * val;
        }

        throw invalid_argument{"Units do not match - [" + unit_name_1 + "] cannot be converted to [" + unit_name_2 + "]"};
    }

    /**
     * @param numberWithUnits1
     * @param numberWithUnits2
     * @return 1 - if the first object is bigger, 0 - if they are equal, -1 - if the first object is smaller
     */
    int compare_units(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        double x1 = abs((num1.unit_quantity + EPSILON) -
                        (convert_unit2unit(num2.unit_name,num1.unit_name, num2.unit_quantity)+ EPSILON));
        if(x1 <  EPSILON) {
            return 0;
        }
        double x2 = (num1.unit_quantity + EPSILON) -
                    (convert_unit2unit(num2.unit_name,num1.unit_name, num2.unit_quantity)+ EPSILON);
        return (x2 >  EPSILON) ? 1 : (-x2 >  EPSILON)? -1 : 0;
    }

    /**
     * input / output methods - get or push an object of this class
     * @param ostream1 / istream1
     * @param numberWithUnits
     * @return unit count["unit name"]
     */
    ostream &operator<<(ostream &ostream1, const NumberWithUnits &numberWithUnits) {
        ostream1 << numberWithUnits.unit_quantity << "[" << numberWithUnits.unit_name << "]";
        return ostream1;
    }

    istream &operator>>(istream &istream1, NumberWithUnits &numberWithUnits1) {
        string unit_name;
        string equals_symbol;
        double num = NEPSILON;
        char c1 = '0', c2 = '0';
        uint size;
        istream1 >> num >> c1 >> unit_name;
        size = unit_name.length();
        if(unit_name.at(size -1) != ']'){
            istream1 >> c2;
        }else{
            unit_name = unit_name.substr(0, size - 1);
        }
        numberWithUnits1 = NumberWithUnits(num, unit_name);
        return istream1;
    }

    /**
     * Overloading the operator (-)
     * @func1 - (a - b)
     * @func2 - (a - 5.5)
     * @func3 - (5.5 - a)
     * @func4 -     (- a)
     */
    NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        double num2con = convert_unit2unit(num2.unit_name, num1.unit_name, num2.unit_quantity);
        return NumberWithUnits(num1.unit_quantity - num2con, num1.unit_name);
    }

    NumberWithUnits operator-(const NumberWithUnits &numberWithUnits, double x) {
        return NumberWithUnits(numberWithUnits.unit_quantity - x, numberWithUnits.unit_name);
    }

    NumberWithUnits operator-(double x, const NumberWithUnits &num) {
        return NumberWithUnits(x - num.unit_quantity, num.unit_name);
    }

    NumberWithUnits operator-(const NumberWithUnits &num) {
        return NumberWithUnits(0 - num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (+)
     * @func1 - (a + b)
     * @func2 - (a + 5.5)
     * @func3 - (5.5 + a)
     * @func4 -     (+ a)
     */
    NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        double num2con = convert_unit2unit(num2.unit_name, num1.unit_name, num2.unit_quantity);
        return NumberWithUnits(num1.unit_quantity + num2con, num1.unit_name);
    }

    NumberWithUnits operator+(const NumberWithUnits &num1, double x) {
        return NumberWithUnits(num1.unit_quantity + x, num1.unit_name);
    }

    NumberWithUnits operator+(double x, const NumberWithUnits &num) {
        return NumberWithUnits(x + num.unit_quantity, num.unit_name);
    }

    NumberWithUnits operator+(const NumberWithUnits &num) {
        return NumberWithUnits(num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (*)
     * @func1 - (a * b)
     * @func2 - (a * 5.5)
     * @func3 - (5.5 * a)
     */
    NumberWithUnits operator*(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        double num2con = convert_unit2unit(num2.unit_name, num1.unit_name, num2.unit_quantity);
        return NumberWithUnits(num1.unit_quantity*num2con, num1.unit_name);
    }

    NumberWithUnits operator*(const NumberWithUnits &num, double x) {
        return NumberWithUnits(num.unit_quantity*x,num.unit_name);
    }

    NumberWithUnits operator*(double x, const NumberWithUnits &num) {
        return NumberWithUnits(x * num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (/)
     * @func1 - (a / b)
     * @func2 - (a / 5.5)
     * @func3 - (5.5 / a)
     */
    NumberWithUnits operator/(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        if(num2.unit_quantity == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }

        double num2con = convert_unit2unit(num2.unit_name, num1.unit_name, num2.unit_quantity);
        return NumberWithUnits(num1.unit_quantity / num2con, num1.unit_name);
    }

    NumberWithUnits operator/(const NumberWithUnits &num, double x) {
        if(x == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }
        return NumberWithUnits(num.unit_quantity / x, num.unit_name);
    }

    NumberWithUnits operator/(double x, const NumberWithUnits &num) {
        if(num.unit_quantity == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }
        return NumberWithUnits(x / num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (+=)
     * @func1 - (a += b)
     * @func2 - (a += 5.5)
     * @func3 - (5.5 += a)
     */
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num) {
        double num2con = convert_unit2unit(num.unit_name, this->unit_name, num.unit_quantity);
        this->unit_quantity = this->unit_quantity + num2con;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator+=(const double &x) {
        this->unit_quantity = this->unit_quantity + x;
        return *this;
    }

    NumberWithUnits operator+=(double x, NumberWithUnits &num) {
        return NumberWithUnits(x + num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (-=)
     * @func1 - (a -= b)
     * @func2 - (a -= 5.5)
     * @func3 - (5.5 -= a)
     */
     NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num) {
        double num2con = convert_unit2unit(num.unit_name, this->unit_name, num.unit_quantity);
        this->unit_quantity = this->unit_quantity - num2con;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator-=(const double &x) {
         this->unit_quantity = this->unit_quantity - x;
        return *this;
    }

    NumberWithUnits operator-=(double x, NumberWithUnits &num) {
        return NumberWithUnits(x -= num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (*=)
     * @func1 - (a *= b)
     * @func2 - (a *= 5.5)
     * @func3 - (5.5 *= a)
     */
    NumberWithUnits &NumberWithUnits::operator*=(const NumberWithUnits &num) {
        double num2con = convert_unit2unit(num.unit_name, this->unit_name, num.unit_quantity);
        this->unit_quantity = this->unit_quantity * num2con;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator*=(const double &x) {
        this->unit_quantity = this->unit_quantity * x;
        return *this;
    }

    NumberWithUnits operator*=(double x, NumberWithUnits &num) {
        return NumberWithUnits(x * num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (/=)
     * @func1 - (a /= b)
     * @func2 - (a /= 5.5)
     * @func3 - (5.5 /= a)
     */
    NumberWithUnits &NumberWithUnits::operator/=(const NumberWithUnits &num) {
        if(num.unit_quantity == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }
        double num2con = convert_unit2unit(num.unit_name, this->unit_name, num.unit_quantity);
        this->unit_quantity = this->unit_quantity / num2con;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator/=(const double &x) {
        if(x == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }
        this->unit_quantity = this->unit_quantity / x;
        return *this;
    }

    NumberWithUnits operator/=(double x, NumberWithUnits &num) {
        if(num.unit_quantity == 0){
            throw invalid_argument("Can not divide by 0 !!");
        }
        return NumberWithUnits(x / num.unit_quantity, num.unit_name);
    }

    /**
     * Overloading the operator (==)
     * @func1 - (a == b)
     * @func2 - (a == 5.5)
     * @func3 - (5.5 == a)
     */
    bool operator==(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        double flag = compare_units(num1, num2);
        return flag == 0;
    }

    bool operator==(double x, const NumberWithUnits &num) {
        if(x == num.unit_quantity){
            return true;
        }
        return false;
    }

    bool operator==(const NumberWithUnits &num, double x) {
        if(num.unit_quantity == x){
            return true;
        }
        return false;
    }

    /**
     * Overloading the operator (!=)
     * @func1 - (a != b)
     * @func2 - (a != 5.5)
     * @func3 - (5.5 != a)
     */
    bool operator!=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        int flag = compare_units(num1, num2);
        return flag != 0;
    }

    bool operator!=(const NumberWithUnits &num, double x) {
        if(num.unit_quantity != x){
            return true;
        }
        return false;
    }

    bool operator!=(double x, const NumberWithUnits &num) {
        if(x != num.unit_quantity){
            return true;
        }
        return false;
    }

    /**
     * Overloading the operator (<)
     * @func1 - (a < b)
     * @func2 - (a < 5.5)
     * @func3 - (5.5 < a)
     */
    bool operator<(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        int flag = compare_units(num1, num2);
        return flag == -1;
    }

    bool operator<(const NumberWithUnits &num, double x) {
        if(num.unit_quantity < x){
            return true;
        }
        return false;
    }

    bool operator<(double x, const NumberWithUnits &num) {
        if(x < num.unit_quantity){
            return true;
        }
        return false;
    }


    /**
     * Overloading the operator (>)
     * @func1 - (a > b)
     * @func2 - (a > 5.5)
     * @func3 - (5.5 > a)
     */
    bool operator>(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        int flag = compare_units(num1, num2);
        return flag == 1;
    }

    bool operator>(const NumberWithUnits &num, double x) {
        if(num.unit_quantity > x){
            return true;
        }
        return false;
    }

    bool operator>(double x, const NumberWithUnits &num) {
        if(x > num.unit_quantity){
            return true;
        }
        return false;
    }

    /**
     * Overloading the operator (>=)
     * @func1 - (a >= b)
     * @func2 - (a >= 5.5)
     * @func3 - (5.5 >= a)
     */
    bool operator>=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        int flag = compare_units(num1, num2);
        return (flag >= 0);
    }

    bool operator>=(const NumberWithUnits &num, double x) {
        if(num.unit_quantity >= x){
            return true;
        }
        return false;
    }

    bool operator>=(double x, const NumberWithUnits &num) {
        if(x >= num.unit_quantity){
            return true;
        }
        return false;
    }

    /**
     * Overloading the operator (<=)
     * @func1 - (a <= b)
     * @func2 - (a <= 5.5)
     * @func3 - (5.5 <= a)
     */
    bool operator<=(const NumberWithUnits &num1, const NumberWithUnits &num2) {
        int flag = compare_units(num1, num2);
        return flag <= 0;
    }

    bool operator<=(const NumberWithUnits &num, double x) {
        if(num.unit_quantity <= x){
            return true;
        }
        return false;
    }

    bool operator<=(double x, const NumberWithUnits &num) {
        return false;
    }

    /**
     * Overloading the operator (++)
     * @func1 - (++a)
     * @func2 - (a++)
     */
    NumberWithUnits &NumberWithUnits::operator++() {
        ++(this->unit_quantity);
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int) {
        return NumberWithUnits((this->unit_quantity)++, this->unit_name);
    }

    /**
     * Overloading the operator (++)
     * @func1 - (--a)
     * @func2 - (a--)
     */
    NumberWithUnits &NumberWithUnits::operator--() {
        --(this->unit_quantity);
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator--(int) {
        return NumberWithUnits((this->unit_quantity)--, this->unit_name);
    }


}