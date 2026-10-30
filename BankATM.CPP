#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double balance = 2000;
vector<string> history;

void deposit();
void withdraw();

int main()
{
    int choice;
    const int correctPin = 1234;
    const int maxAttempts = 4;
    int pin;
    int attempts = 0;

    cout << "Welcome Back! \n";

    while (attempts < maxAttempts)
    {
        cout << "Enter your 4-Digit pin: ";
        cin >> pin;
        cout << "\n";
        if (pin == correctPin)
        {
            do
            {
                cout << "=====WELCOME TO YOUR BANK ACCOUNT=====\n";
                cout << "CHOOSE YOUR OPERATION: " << endl;
                cout << "1. Deposit \n";
                cout << "2. Withdraw \n";
                cout << "3. Check balance \n";
                cout << "4. Transaction History \n";
                cout << "5. Exit \n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    deposit();
                    break;
                }
                case 2:
                {
                    withdraw();
                    break;
                }
                case 3:
                {
                    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
                    break;
                }
                case 4:
                {
                    cout << "Transaction history: " << endl;
                    if (history.empty())
                    {
                        cout << "No transactions yet." << endl;
                    }
                    else
                    {
                        for (const string &trans : history)
                        {
                            cout << trans << endl;
                        }
                    }
                    break;
                }
                case 5:
                {
                    cout << "Thank you for using our services. Goodbye!" << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
            } while (choice != 5);
            break; // exit the pin loop after successful menu
        }
        else
        {
            attempts++;
            cout << "Incorrect pin. Please try again. Attempts left: " << maxAttempts - attempts << endl;
        }
    }
    if (attempts == maxAttempts)
    {
        cout << "Too many incorrect attempts. Access denied." << endl;
    }
    return 0;
}

void deposit()
{
    double amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    if (amount > 0)
    {
        balance += amount;
        cout << "You have successfully deposited $" << fixed << setprecision(2) << amount << endl;
        cout << "New balance is $" << fixed << setprecision(2) << balance << endl;
        history.push_back("Deposited $" + to_string(amount));
    }
    else
    {
        cout << "Invalid amount. Deposit must be positive." << endl;
    }
}

void withdraw()
{
    double amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "You have successfully withdrawn $" << fixed << setprecision(2) << amount << endl;
        cout << "New balance is $" << fixed << setprecision(2) << balance << endl;
        history.push_back("Withdrew $" + to_string(amount));
    }
    else if (amount > balance)
    {
        cout << "Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << endl;
    }
    else
    {
        cout << "Invalid amount. Withdrawal must be positive." << endl;
    }
}
