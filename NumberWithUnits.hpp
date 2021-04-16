#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace ariel
{
    class NumberWithUnits{
        private:
            double km, m, kg, g, ton, hour, min, sec, USD, ILS;


        public:
            static void read_units(char filetxt);
            NumberWithUnits();
            // Constactors
            NumberWithUnits(int km, int m, int kg, int g, int ton, int h, int min, int sec, int USD, int ILS);

            // ostream& operator+();

            // Comperation Operator Overload
            friend bool operator==(NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator!=(NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>(NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>=(NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<=(NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<(NumberWithUnits& n1, NumberWithUnits& n2);
            


    };
} // namespace ariel
