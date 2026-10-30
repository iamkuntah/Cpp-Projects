#include <iostream>
#include <cmath>

using namespace std;

int main() {

cout<< "Enter the radius: ";

double Radius;
double Area;
const double pi = 3.14;


cin>> Radius;

Area = pi * pow(Radius, 2);
cout<< "The area of the circle is: " << Area;



return 0;
}
