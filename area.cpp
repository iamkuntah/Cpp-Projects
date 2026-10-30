#include <iostream>
#include <cmath>

using namespace std;

int main() {

   double area;
   int choice;

   cout<< "choose a shape to calculate the area: "<<endl;
   cout<< "1.circle "<<endl;
   cout<< "2.triangle "<<endl;
   cout<< "3.rectangle "<<endl;
   cout<< "4.square "<<endl;
   cout<< "Enter your choice (1/2/3/4): ";
   cin>> choice;

if (choice == 1) {
   double radius;
   const double pi = 3.142;

   cout<< "Enter the radius of the circle: ";
   cin>> radius;

   area = (pi * pow(radius, 2));

   cout<< "The area of the circle is: "<<area<<endl;
}

else if (choice == 2) {
   double base;
   double height;

   cout<< "Enter the base of the triangle: ";
   cin>> base;
   cout<< "Enter the height of the triangle: ";
   cin>> height;
   const double half = 0.5;

   area = (half*base*height);

   cout<< "The area of the triangle is: "<<area<<endl;
}

else if (choice == 3) {
   double length;
   double width;

   cout<< "Enter the length of the rectangle: ";
   cin>> length;
   cout<< "Enter the width of the rectangle: ";
   cin>> width;

   area = (length * width);

   cout<< "The area of the rectangle is: "<<area<<endl;
}

else if (choice == 4) {
  double length;

  cout<< "Enter the length of the square: ";
  cin>>length;

  area = pow(length,2);

  cout<< "The area of the square is: "<<area<<endl;

}

else {
   cout<< "invalid choice! please enter the numbers 1,2,3."<<endl;
}


return 0;
}
