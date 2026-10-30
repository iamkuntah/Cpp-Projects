#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    double num;

    cout << "Enter the number: ";
    cin >> num; // prompts the user to key in the number.

    cout << fixed << setprecision(4); // rounds up to 4 decimal places.
    cout << "with fixed: " << num << endl;

    cout.unsetf(ios::fixed);
    cout << setprecision(4); // gives 4 significant figures.
    cout << "without fixed: " << num << endl;

    return 0;
}
