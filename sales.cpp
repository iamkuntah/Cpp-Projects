#include <iostream>

using namespace std;

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

int main()
{
    int choice;
    double num1;
    double num2;
    int operation;
    do
    {

        cout << "1. Addition.\n";
        cout << "2. Subtraction.\n";
        cout << "3. Multiplication.\n";
        cout << "4. Division.\n";
        cout << "5. Exit.\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter two numbers.\n";
            cout << "First: ";
            cin >> num1;
            cout << "Second: ";
            cin >> num2;
            cout << "result = " << add(num1, num2);
            break;

        case 2:
            cout << "Enter two numbers.\n";
            cout << "First: ";
            cin >> num1;
            cout << "Second: ";
            cin >> num2;
            cout << "result = " << subtract(num1, num2);
            break;

        case 3:
            cout << "Enter two numbers.\n";
            cout << "First: ";
            cin >> num1;
            cout << "Second: ";
            cin >> num2;
            cout << "result = " << multiply(num1, num2);
            break;

        case 4:
            cout << "Enter two numbers.\n";
            cout << "First: ";
            cin >> num1;
            cout << "Second: ";
            cin >> num2;
            if (num2 == 0)
            {
                cout << "Invalid!! cannot divide by zero!\n";
            }
            else
            {
                cout << "result = " << divide(num1, num2);
            }
        case 5:
            cout << "Exiting...." << endl;
        }
    } while (choice = !5);

    return 0;
}
