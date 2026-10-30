#include <iostream>
#include <iomanip>

using namespace std;

double cToP(double c)
{
  return (c * 2.20462);
}

int main() {

  double weight;

  cout<< "Enter the weight: ";
  cin>> weight;

  double result = cToP(weight);


  cout<< "weight: "<< result<< endl;





return 0;
}
