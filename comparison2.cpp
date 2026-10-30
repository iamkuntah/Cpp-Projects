#include <iostream>
#include <cmath>

using namespace std;

int main() {

double num1;
double num2;
double num3;
double num4;


cout<< "Enter the first number: ";
cin>> num1;

cout<< "Enter the second number: ";
cin>> num2;

cout<< "Enter the third number: ";
cin>> num3;

cout<< "Enter the fourth number: ";
cin>> num4;

int largest = num1;

if (num2 > largest) {
  largest = num2;
}

if (num3 > largest) {
  largest = num3;
}

if (num4 > largest) {
  largest = num4;
}

cout<< "The largest number is: "<<largest<<endl;

return 0;
}
