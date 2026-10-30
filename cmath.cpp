#include <iostream>

using namespace std;

int num(int a, int b, int c)
{
   if (a >= b && a >= c)
   {
      return a;
   }
   else if (b >= a && b >= c)
   {
      return b;
   }
   else
   {
      return c;
   }
}

int main()
{

   int a;
   int b;
   int c;

   cout << "Enter the first number: ";
   cin >> a;

   cout << "Enter the second number: ";
   cin >> b;

   cout << "Enter the third number: ";
   cin >> c;

   int result = num(a, b, c);

   if (a == b && b == c)
   {
      cout << "The numbers are equal!" << endl;
   }
   else
   {
      cout << "The greater number is: " << result << endl;
   }

   return 0;
}