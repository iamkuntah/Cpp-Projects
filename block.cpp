#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {

double num1;
double num2;
char choice;
char operation;

do
  {
  cout<< "Enter the first number: ";
  cin>> num1;

  cout<< "Choice the operation to be done:(+, -, /, *): ";
  cin>> operation;

  cout<< "Enter the second number: ";
  cin>> num2;



  switch (operation) {

  case '+':
  {
  cout<< "result = "<< (num1 + num2) << endl;
  }
  break;

  case '-':
  {
    cout<< "result = "<< (num1 - num2) << endl;
  }
  break;

  case '/':
  if (num2 != 0)
    {
      cout<< "result = "<< (num1 / num2)<< endl;
    }
  else
    {
      cout<< "ERROR cannot be divided by ZERO! "<< endl;
    }
  break;

  case '*':
    {
      cout<< "result = "<< (num1 * num2)<< endl;
    }
  break;

  default:
    cout<< "Invalid operation! "<< endl;
      }

  cout<< "Would you like to perform another operation? (Y / N):";
  cin>> choice;
  cout<< endl;
  }
while (choice == 'y' || choice == 'Y');

cout<< "Thank you! "<< endl;

  return 0;
}
