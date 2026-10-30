#include <iostream>

using namespace std;

int add(int a , int b)
{
  return a + b;
}

int main(){

int a;
int b;

cout<< "Enter the numbers to add."<< endl;
cout<< "Enter the first one: ";
cin>> a;
cout<< "Enter the second number: ";
cin>> b;

int result = add (a , b);
cout<< "Result = "<< result;

return 0;
}
