#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

double balance = 1000.00;

vector<string> history;
void deposit(double amount);
void withdraw(double amount);

int main()
{

  int pin;
  const int correctPin = 1234; // the account's pin.
  int attempts = 0;
  const int maxAttempts = 3; // number of attempts for the pin.
  bool accessGranted = true;

  cout << "Welcome back!!" << endl;

  while (attempts < maxAttempts)
  {

    cout << "Enter your 4-Digit pin: ";
    cin >> pin;
    cout << "\n";

    if (pin == correctPin)
    {
      accessGranted = true;
      break; // Exit the loop.
    }
    else
    {
      attempts++;
      cout << "Incorrect pin! Try Again! " << (maxAttempts - attempts) << " attempts left." << endl;
    }
  }
  // after the loop.

  if (!accessGranted)
  {
    cout << "Too many wrong attempt(s)!" << endl;
    cout << "ACCOUNT LOCKED!!" << endl;
    cout << "CONTACT CUSTOMER SERVICE!" << endl;
  }
  return 0;

  cout << "Access Granted! WELCOME!" << endl;

  double choice;
  double amount;

  do
  {

    cout << "1.Deposit.\n";
    cout << "2.Withdraw.\n";
    cout << "3.Exit.\n";
    cout << "4.Check Balance.\n";
    cout << "5.Transaction History.\n";
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 1)
    {
      cout << "Enter the amount: ";
      cin >> amount;
      deposit(amount);
    }
    else if (choice == 2)
    {
      cout << "Enter the amount: ";
      cin >> amount;
      withdraw(amount);
    }
    else if (choice == 3)
    {
      cout << "See you later..." << endl;
    }
    else if (choice == 4)
    {
      cout << "Current Balance: " << "USD " << balance << endl;
    }
    else if (choice == 5)
    {
      cout << "\n--- Transaction History ---\n";
      if (history.empty())
      {
        cout << "No transactions yet.\n";
      }
      else
      {
        for (int i = 0; i < history.size(); i++)
        {
          cout << i + 1 << ". " << history[i] << endl;
        }
      }
    }
    else
    {
      cout << "Invalid character!!" << endl;
    }
  } while (choice != 3); // The program still runs until the user chooses exit.
}

void deposit(double amount)
{
  balance += amount;
  history.push_back("Deposited: " + to_string(amount));

  cout << "Deposited: " << amount << endl;
  cout << "Deposited: " << amount << endl;
  cout << "New Balance: " << balance << endl;
}

void withdraw(double amount)
{
  if (amount < balance)
  {
    balance -= amount;
    history.push_back("Withdrew: " + to_string(amount));

    cout << "Withdrew: " << amount << endl;
    cout << "New Balance: " << balance << endl;
  }
  else
  {
    cout << "Insufficient Funds!!" << endl;
    history.push_back("failed withdrawal attempt of: " + to_string(amount));
  }
}