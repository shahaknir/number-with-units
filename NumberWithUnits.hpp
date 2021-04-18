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
            static void read_units(ifstream& filetxt);

            // Constactors
            NumberWithUnits();
            NumberWithUnits(int num, string a);
            
            // Numeric operators
            friend NumberWithUnits operator+(NumberWithUnits& a, const NumberWithUnits b);
            friend NumberWithUnits operator+=(NumberWithUnits& a, const NumberWithUnits b);
            friend NumberWithUnits operator-(NumberWithUnits& a, const NumberWithUnits b);
            friend NumberWithUnits operator-=(NumberWithUnits& a, const NumberWithUnits b);
            friend NumberWithUnits operator*(double other, NumberWithUnits& a);
            // friend NumberWithUnits operator*(int other, NumberWithUnits& a);

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
            friend bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2);
            friend bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2);
            friend bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2);
            friend bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2);
            friend bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2);
            friend bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2);
            
            // Streamming Operator Overload
            friend ostream& operator>>(ostream& input, const NumberWithUnits& num);
            friend ostream& operator<<(ostream& output, const NumberWithUnits& num);
            friend istringstream& operator>>(istringstream& input, const NumberWithUnits& num);
            friend istringstream& operator<<(istringstream& output, const NumberWithUnits& num);

    };
} // namespace ariel
