#include <iostream>
using namespace std;

int main() {

cout<< "Enter values for x and y : ";

double x;
double y;

cin>> x;
cin>>y;


double temp = x;
x = y;
y = temp;

cout<< "x = "<< x<<endl;
cout<< "y = "<< y;

return 0;



}
