#include "NumberWithUnits.hpp"

namespace ariel{

    void read_units(){}
    NumberWithUnits::NumberWithUnits(): km(0), m(0), kg(0),g(0),ton(0),hour(0),min(0),sec(0),USD(0),ILS(0){}
    NumberWithUnits::NumberWithUnits(int km, int m, int kg, int g, int ton, int h, int min, int sec, int USD, int ILS):
                km(km), m(m), kg(kg),g(g),ton(ton),hour(h),min(min),sec(sec),USD(USD),ILS(ILS) {}


    bool operator==(NumberWithUnits& n1, NumberWithUnits& n2){}
    bool operator!=(NumberWithUnits& n1, NumberWithUnits& n2){}
    bool operator>(NumberWithUnits& n1, NumberWithUnits& n2){}
    bool operator>=(NumberWithUnits& n1, NumberWithUnits& n2){}
    bool operator<=(NumberWithUnits& n1, NumberWithUnits& n2){}
    bool operator<(NumberWithUnits& n1, NumberWithUnits& n2){}
            





}