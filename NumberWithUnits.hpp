#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace ariel
{
    class NumberWithUnits{
        private:
            int t;
            string const temp[5];

        public:
            static char read_units(char filetxt);
            
            // Constactors
            NumberWithUnits();
            NumberWithUnits(int t, string const& a);
            
            // Numeric operators
            friend NumberWithUnits operator+(const NumberWithUnits& a, NumberWithUnits b);
            friend NumberWithUnits operator+=(const NumberWithUnits& a, NumberWithUnits b);
            friend NumberWithUnits operator-(const NumberWithUnits& a, NumberWithUnits b);
            friend NumberWithUnits operator-=(const NumberWithUnits& a, NumberWithUnits b);
            friend NumberWithUnits operator*(const NumberWithUnits& a, double other);
            
            friend NumberWithUnits operator+(unsigned int a, NumberWithUnits b);
            friend NumberWithUnits operator+=(unsigned int a, NumberWithUnits b);
            friend NumberWithUnits operator-(unsigned int a, NumberWithUnits b);
            friend NumberWithUnits operator-=(unsigned int a, NumberWithUnits b);

            // ++ --
            friend NumberWithUnits operator++(NumberWithUnits& a);
            friend NumberWithUnits operator--(NumberWithUnits& a);

            // Uneric + & -
            friend const NumberWithUnits operator+(NumberWithUnits& a);
            friend const NumberWithUnits operator-(NumberWithUnits& a);
            
            // Comperation Operator Overload
            friend bool operator==(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator!=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<(const NumberWithUnits& n1, NumberWithUnits& n2);
            
            // Streamming Operator Overload
            friend ostream& operator>>(ostream& input, NumberWithUnits& num);
            friend ostream& operator<<(ostream& output, NumberWithUnits& num);

    };
} // namespace ariel
