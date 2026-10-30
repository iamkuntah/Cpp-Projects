#include <iostream>
#include <iomanip>

using namespace std;

double balance = 1000.00;
void deposit (double amount);
void withdraw (double amount);

int main ()
{

  int pin;
  const int correctPin = 3210;// the account's pin.
  int attempts = 0;
  const int maxAttempts = 3;
  bool accessGranted = false;

  while (attempts < maxAttempts)
  {
    cout<< "Welcome back!!"<< endl;
    cout<< "Enter your 4-Digit pin: ";
    cin>> pin;

    if (pin == correctPin)
    {
      accessGranted = true;
      break; // Exit the loop.
    }
    else
    {
      attempts++;
      cout<< "Incorrect pin! Try Again! "<< (maxAttempts - attempts)<< " attempts left."<< endl;
    }

    if (!accessGranted)
    {
      cout<< "Too many wrong attempts. Account Locked! Please contact customer care!"<< endl;
    }
    return 0;
  }

  cout<< "Access Granted! Welcome!"<< endl;

  double choice;
  double amount;
  cout<< "1.Deposit.\n";
  cout<< "2.Withdraw.\n";
  cout<< "3.Exit.\n";
  cout<< "4.Check Balance.\n";
  cout<< "Enter your choice: ";

  cin>> choice;

  if (choice == 1)
  {
    cout<< "Enter the amount: ";
    cin>> amount;
    deposit (amount);
  }
  else if (choice == 2)
  {
    cout<< "Enter the amount: ";
    cin>> amount;
    withdraw (amount);
  }
  else if (choice == 3)
  {
    cout<< "See you later..."<< endl;
  }
  else if (choice == 4)
  {
    cout<< "Current Balance: "<<"USD "<< balance<< endl;
  }
  else
  {
    cout<< "Invalid character!!"<< endl;
  }


return 0;
}

void deposit (double amount)
{
  balance += amount;
  cout<< "Deposited: "<< amount<< endl;
  cout<< "New Balance: "<< balance<< endl;
}

void withdraw (double amount)
{
  if (amount < balance)
    {
      balance -= amount;
      cout<< "Withdrew: "<< amount <<endl;
      cout<< "New Balance: "<< balance <<endl;
    }
  else
  {
    cout<< "Insufficient Funds!!"<< endl;
  }

}
