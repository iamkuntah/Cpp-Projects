#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    int choice;
    char operation;
    double Area;

    do
    {

        cout << "===== CALCULATOR =====" << endl;
        cout << "calculation options: " << endl;
        cout << "1. Triangle.\n";
        cout << "2. Square.\n";
        cout << "3. Rectangle.\n";
        cout << "4. Circle.\n";
        cout << "5. Quit.\n";

        cout << "Enter the one you want to calculate. ";
        cout << "(T, S, R, C, Q): ";
        cin >> operation;

        switch (operation)
        {
        case 'T':
        case 't':
        {
            double base;
            double height;

            cout << "Enter the base of the triangle: ";
            cin >> base;

            cout << "Enter the height of the triangle: ";
            cin >> height;

            Area = (base * height);

            cout << "The area of the triangle is: " << Area << "\n";
        }
        break;
        case 'S':
        case 's':
        {
            float length;

            cout << "Enter the length of the square: ";
            cin >> length;

            Area = (pow(length, 2));

            cout << "The area of the square is: " << Area << endl;
        }
        break;
        case 'R':
        case 'r':
        {
            double length;
            double width;

            cout << "Enter the length of the rectangle: ";
            cin >> length;

            cout << "Enter the width of the rectangle: ";
            cin >> width;

            Area = (length * width);

            cout << "The area of the rectangle is: " << Area << endl;
        }
        break;
        case 'C':
        case 'c':
        {
            const float pi = 3.124;
            float radius;

            cout << "Enter the radius of the circle: ";
            cin >> radius;

            Area = (pi * (pow(radius, 2)));

            cout << "The area of the circle is: " << Area << endl;
        }
        break;
        case 'Q':
        case 'q':
        {
            cout << "Goodbyee!" << endl;
        }

        default:
        {
            cout << "Wacha ufala" << endl;
        }
        break;
        }
    } while (operation != 'Q' && operation != 'q');

    return 0;
}