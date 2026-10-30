#include <iostream>
#include <cmath>
using namespace std;
int main()
{

  double area;
  int choice;

  cout << "Enter the shape to calculate" << endl;
  cout << "1. Triangle" << endl;
  cout << "2. Circle" << endl;
  cout << "3. Rectangle" << endl;
  cout << "Enter either 1 / 2 / 3: ";
  cin >> choice;

  if (choice == 1)
  {
    double base;
    double height;

    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << "Enter the height of the triangle: ";
    cin >> height;
    const double half = 0.5;
    area = (half * base * height);

    cout << "The area of the triangle is: " << area << endl;
  }

  else if (choice == 2)
  {
    double radius;
    const float pi = 3.142;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    area = (pi * (pow(radius, 2)));

    cout << "The area of the circle is: " << area << endl;
  }

  else if (choice == 3)
  {

    double length;
    double width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width: ";
    cin >> width;

    area = (length * width);

    cout << "The area of the rectangle is: " << area << endl;
  }

  else
  {
    cout << "please choose from the numbers above" << endl;
  }
  return 0;
}
