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
            
            friend NumberWithUnits operator+(unsigned int a, const NumberWithUnits b);
            friend NumberWithUnits operator+=(unsigned int a, const NumberWithUnits b);
            friend NumberWithUnits operator-(unsigned int a, const NumberWithUnits b);
            friend NumberWithUnits operator-=(unsigned int a, const NumberWithUnits b);

            // ++ --
            friend NumberWithUnits operator++(const NumberWithUnits& a);
            friend NumberWithUnits operator--(const NumberWithUnits& a);

            // Uneric + & -
            friend const NumberWithUnits operator+(const NumberWithUnits& a);
            friend const NumberWithUnits operator-(const NumberWithUnits& a);
            
            // Comperation Operator Overload
            friend bool operator==(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator!=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator>=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<=(const NumberWithUnits& n1, NumberWithUnits& n2);
            friend bool operator<(const NumberWithUnits& n1, NumberWithUnits& n2);
            
            // Streamming Operator Overload
            friend ostream& operator>>(ostream& input, const NumberWithUnits& num);
            friend ostream& operator<<(ostream& output, const NumberWithUnits& num);

    };
} // namespace ariel
