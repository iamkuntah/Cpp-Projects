#include<iostream>

using namespace std;

int main() {

double num1;
double num2;
char operation;

cout<< "Enter the first number: ";
cin>> num1;

cout<< "choose the operation to be done: (*, +, /, -): ";
cin>> operation;

cout<< "Enter the second number: ";
cin>> num2;

switch (operation) {

case '+':
  cout<< "result: "<< (num1 + num2)<<endl;

case '-':
  cout<< "result: "<<(num1 - num2)<<endl;

case '*':
  cout<< "result: "<<(num1 * num2)<<endl;

case '/':
  if (num2 )
  cout<< "result: "<<(num1 / num2)<<endl;
}


return 0;
}
