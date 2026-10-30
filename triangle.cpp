#include <iostream>
#include <cmath>

using namespace std;

int main() {

double height;
double base;
double area;

cout<< "Enter the base of the triangle: ";
cin>> base;
cout<< "Enter the height of the triangle: ";
cin>> height;

const double half = .5;

area = (half * base * height);

cout<< "The area of the triangle is: "<<area<<endl;


return 0;
}
