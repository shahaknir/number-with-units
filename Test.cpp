//
// Created by shahak on 10/06/2021.
//

#include <string>
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "NumberWithUnits.hpp"
#include <ctime>
#include <stdexcept>
#include <random>

using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};

std::random_device random_engine;
int max_range = UINT16_MAX;
std::uniform_int_distribution<int> random_num_range(0, max_range);


/**
 * Test for the operator +
 */
TEST_CASE("test for the operator +"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{54, "m"};
    NumberWithUnits b{12, "km"};
    NumberWithUnits c;
    NumberWithUnits d{6, "sec"};
    NumberWithUnits e{1, "ILS"};
    c = a + b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5;
    for(int i = 0; i < 100; i++){
        double random = (random_num_range(random_engine)) * 100;
        result = result + random;
        CHECK_EQ((c = c + random) , NumberWithUnits{result, "km"});
        result += random;
        CHECK_EQ((c = c + random) , NumberWithUnits{result, "km"});
        result = random + result;
        CHECK_EQ((c = random+(-c)) , NumberWithUnits{result, "km"});
        result += -1;
        CHECK_EQ((c += -1) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator -
 */
TEST_CASE("test for the operator -"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{50, "m"};
    NumberWithUnits b{12, "km"};
    NumberWithUnits c;
    NumberWithUnits d{6, "sec"};
    NumberWithUnits e{1, "ILS"};
    c = a - b;
    CHECK_EQ(c , NumberWithUnits{12.95, "km"});
    double result = 1.5;
    for(int i = 0; i < 100; i++){
        double random = (random_num_range(random_engine)) * 100;
        result = result - random;
        CHECK_EQ((c = c - random) , NumberWithUnits{result, "km"});
        result -= random;
        CHECK_EQ((c = c - random) , NumberWithUnits{result, "km"});
        result = random - (-result) ;
        CHECK_EQ((c = random-(-c)) , NumberWithUnits{result, "km"});
        result *= -1;
        CHECK_EQ((c = -c) , NumberWithUnits{result, "km"});
    }

}

/**
 * Test for the operator *
 */
TEST_CASE("test for the operator *") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{54, "m"};
    NumberWithUnits b{12, "km"};
    NumberWithUnits c;
    NumberWithUnits d{6, "sec"};
    NumberWithUnits e{1, "ILS"};
    c = a * b;
    CHECK_EQ(c, NumberWithUnits{648, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result = result * random;
        CHECK_EQ((c = c * random), NumberWithUnits{result, "km"});
        result *= random;
        CHECK_EQ((c = c * random), NumberWithUnits{result, "km"});
        result = random * (-result);
        CHECK_EQ((c = random * (-c)), NumberWithUnits{result, "km"});
        result *= -1;
        CHECK_EQ((c = -c), NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator /
 */
TEST_CASE("test for the operator /") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{500, "m"};
    NumberWithUnits c;
    NumberWithUnits d{500, "ILS"};
    NumberWithUnits e{500, "sec"};
    c = a / b;
    CHECK_EQ(c, NumberWithUnits{1.5, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result = result / random;
        CHECK_EQ((c = c / random), NumberWithUnits{result, "km"});
        result /= random;
        CHECK_EQ((c = c / random), NumberWithUnits{result, "km"});
        result = random / (-result);
        CHECK_EQ((c = random / (-c)), NumberWithUnits{result, "km"});
        result /= -1;
        CHECK_EQ((c = -c), NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator +=
 */
TEST_CASE("test for the operator +=") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{500, "m"};
    NumberWithUnits c;
    NumberWithUnits d{500, "ILS"};
    NumberWithUnits e{500, "sec"};
    c += a + b;
            CHECK_EQ(c, NumberWithUnits{2.5, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result += result / random;
        CHECK_EQ((c += c + random), NumberWithUnits{result, "km"});
        result += random;
        CHECK_EQ((c += c + random), NumberWithUnits{result, "km"});
        result += random / (-result);
        CHECK_EQ((c += random + (-c)), NumberWithUnits{result, "km"});
        result += -1;
        CHECK_EQ((c += -c), NumberWithUnits{0, "km"});
    }
}

/**
 * Test for the operator -=
 */
TEST_CASE("test for the operator -=") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{500, "m"};
    NumberWithUnits c;
    NumberWithUnits d{500, "ILS"};
    NumberWithUnits e{500, "sec"};
    c -= a + b;
    CHECK_EQ(c, NumberWithUnits{1.5, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result -= result / random;
        CHECK_EQ((c = c + random), NumberWithUnits{result, "km"});
        result -= random;
        CHECK_EQ((c -= c + random), NumberWithUnits{result, "km"});
        result -= random / (-result);
        CHECK_EQ((c -= random + (-c)), NumberWithUnits{result, "km"});
        result -= -1;
        CHECK_EQ((c += -c), NumberWithUnits{0, "km"});
    }
}

/**
 * Test for the operator *=
 */
TEST_CASE("test for the operator *=") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{500, "m"};
    NumberWithUnits c;
    NumberWithUnits d{500, "ILS"};
    NumberWithUnits e{500, "sec"};
    c *= a + b;
            CHECK_EQ(c, NumberWithUnits{2.5, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result *= result + random;
        CHECK_EQ((c = c + random), NumberWithUnits{result, "km"});
        result = random;
        CHECK_EQ((c *= (1/c) + random), NumberWithUnits{result, "km"});
        result *= random / (-result);
        CHECK_EQ((c -= random + (-c)), NumberWithUnits{result, "km"});
        result *= -1;
        CHECK_EQ((c += -c), NumberWithUnits{0, "km"});
    }
}

/**
 * Test for the operator /=
 */
TEST_CASE("test for the operator /=") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{500, "m"};
    NumberWithUnits c;
    NumberWithUnits d{500, "ILS"};
    NumberWithUnits e{500, "sec"};
    c = a / b;
    CHECK_EQ(c, NumberWithUnits{4, "km"});
    double result = 1.5;
    for (int i = 0; i < 100; i++) {
        double random = (random_num_range(random_engine)) * 100;
        result = result / random;
        CHECK_EQ((c = c / random), NumberWithUnits{result, "km"});
        result /= random;
        CHECK_EQ((c = c / random), NumberWithUnits{result, "km"});
        result = random / (-result);
        CHECK_EQ((c = random / (-c)), NumberWithUnits{result, "km"});
        result /= -1;
        CHECK_EQ((c = -c), NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator ==
 */
TEST_CASE("test for the operator =="){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};

    CHECK((numberWithUnits1 == numberWithUnits2) == 0);//false == 0
    CHECK((numberWithUnits2 == numberWithUnits1) == 0);
    CHECK((numberWithUnits2 == numberWithUnits2) == 1);//true == 1
    CHECK((numberWithUnits1 == numberWithUnits1) == 1);
    CHECK((numberWithUnits1 == 2) == 1);
    CHECK((2 == numberWithUnits1) == 1);
}

/**
 * Test for the operator !=
 */
TEST_CASE("test for the operator !="){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};
    NumberWithUnits c;

    CHECK((numberWithUnits1 != numberWithUnits2) == 1);//true == 1
    CHECK((numberWithUnits2 != numberWithUnits1) == 1);
    CHECK((c != numberWithUnits1) == 1);
    CHECK((numberWithUnits1 != c) == 1);

    CHECK((numberWithUnits2 != numberWithUnits2) == 0);//false == 0
    CHECK((numberWithUnits1 != numberWithUnits1) == 0);
    CHECK((numberWithUnits1 != 3) == 1);
    CHECK((5 != numberWithUnits1) == 1);
}

/**
 * Test for the operator <
 */
TEST_CASE("test for the operator <"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};


    CHECK((numberWithUnits1 < numberWithUnits2) == 0);//false == 0
    CHECK((numberWithUnits2 < numberWithUnits1) == 1);//true == 1

    CHECK((numberWithUnits1 < 3) == 1);
    CHECK((5 < numberWithUnits1) == 0);
}

/**
 * Test for the operator <=
 */
TEST_CASE("test for the operator <="){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};

    CHECK((numberWithUnits1 <= numberWithUnits2) == 0);//false == 0
    CHECK((numberWithUnits2 <= numberWithUnits1) == 1);//true == 1

    CHECK((numberWithUnits1 <= 3) == 1);
    CHECK((5 <= numberWithUnits1) == 0);
}

/**
 * Test for the operator >
 */
TEST_CASE("test for the operator >"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};

    CHECK((numberWithUnits1 > numberWithUnits2) == 1);//true == 1
    CHECK((numberWithUnits2 > numberWithUnits1) == 0);//false == 0

    CHECK((numberWithUnits1 > 3) == 0);
    CHECK((5 > numberWithUnits1) == 1);
}

/**
 * Test for the operator >=
 */
TEST_CASE("test for the operator >="){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits numberWithUnits1{2, "km"};
    NumberWithUnits numberWithUnits2{500, "m"};

    CHECK((numberWithUnits1 >= numberWithUnits2) == 1);//true == 1
    CHECK((numberWithUnits2 >= numberWithUnits1) == 0);//false == 0

    CHECK((numberWithUnits1 >= 3) == 0);
    CHECK((5 >= numberWithUnits1) == 1);
}


/**
 * Test for the operator ++
 */
TEST_CASE("test for the operator ++") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{54, "m"};
    NumberWithUnits b{12, "km"};

    CHECK_EQ(a++, NumberWithUnits{54, "km"});
    CHECK_EQ(++a, NumberWithUnits{56, "m"});

    CHECK_EQ(b++, NumberWithUnits{12, "km"});
    CHECK_EQ(++b, NumberWithUnits{14, "km"});

}

/**
 * Test for the operator --
 */
TEST_CASE("test for the operator --") {
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{54, "m"};
    NumberWithUnits b{12, "km"};


    CHECK_EQ(a--, NumberWithUnits{54, "km"});
    CHECK_EQ(a, NumberWithUnits{53, "km"});
    CHECK_EQ(--a, NumberWithUnits{52, "m"});
    CHECK_EQ(a, NumberWithUnits{52, "km"});


    CHECK_EQ(b, NumberWithUnits{12, "km"});
    CHECK_EQ(b--, NumberWithUnits{12, "km"});
    CHECK_EQ(b, NumberWithUnits{11, "km"});
    CHECK_EQ(--b, NumberWithUnits{10, "km"});
    CHECK_EQ(b, NumberWithUnits{10, "km"});

}

/**
 * Input & Output Test
 */
TEST_CASE("Input & Output Test"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{54, "m"};
    NumberWithUnits b{12, "km"};

    NumberWithUnits d{6, "sec"};
    NumberWithUnits e{1, "ILS"};

    istringstream input1 {"12000 [ m ]"};
    istringstream input2 {"5400 [ cm ]"};

    input1 >> d;
    input2 >> e;

    ostringstream d_out;
    ostringstream e_out;
    d_out << d;
    e_out << e;
    CHECK_EQ(d_out.str(), "12000[m]");
    CHECK_EQ(e_out.str(), "5400[cm]");
}
