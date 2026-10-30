#include <iostream> // for inputs and outputs (cin and cout)
#include <cmath>
#include <iomanip> // for manipulators like fixed, setprecision, showpoint.

using namespace std;

int main()
{

    double num = 123.456789;

    cout << fixed << showpoint << setprecision(2) << num;
    cout << "Showpoint: " << num << endl;
    // fixed shows numbers in normal decimal form
    // showpoint forces decimal point even for whole numbers
    // setprecision(6) shows 6 digits after the decimal point

    cout.unsetf(ios::fixed); // clears the previous fixed formatting
    cout << showpoint << setprecision(6);
    cout << "without fixed: " << num << endl;

    // setprecision without fixed shows number with 6 significant digits (not necessarily after the decimal place)

    cout.unsetf(ios::fixed | ios::showpoint); // clears the previous formatting
    cout << fixed << scientific << setprecision(6);
    cout << "with fixed: " << num << endl;
    // scientific displays in scientific notation(e.g. 1.2345678e+02)
    // combining fixed and scientific is redundant but for demonstration only

    cout.unsetf(ios::fixed | ios::scientific); // clear both fixed and scientific flags
    cout << scientific << setprecision(6);
    cout << "without fixed: " << num << endl;
    // displays in scientific notation with 6-digits after decimal

    return 0;
}
