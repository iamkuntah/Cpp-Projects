#include <iostream>
using namespace std;

// ========= BASE CLASS =========
class Shape
{
public:
    virtual void area() = 0; // runtime polymorphism
};

// ========= HIERARCHICAL INHERITANCE =========
class Circle : public Shape
{
public:
    void area()
    {
        cout << "Area of Circle = pi * r * r" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void area()
    {
        cout << "Area of Rectangle = l * w" << endl;
    }
};

// ========= SINGLE INHERITANCE =========
class Vehicle
{
public:
    virtual void start()
    {
        cout << "Vehicle starting" << endl;
    }
};

class Car : public Vehicle
{
public:
    void start()
    { // overriding
        cout << "Car starts with key" << endl;
    }

    // compile-time polymorphism
    void horn()
    {
        cout << "Beep!" << endl;
    }

    void horn(int n)
    {
        for (int i = 0; i < n; i++)
            cout << "Beep ";
        cout << endl;
    }
};

// ========= MULTILEVEL INHERITANCE =========
class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog barks" << endl;
    }
};

class Puppy : public Dog
{
public:
    void sound()
    {
        cout << "Puppy barks softly" << endl;
    }
};

// ========= MULTIPLE INHERITANCE =========
class Person
{
public:
    void info()
    {
        cout << "I am a person" << endl;
    }
};

class Employee
{
public:
    void job()
    {
        cout << "I am an employee" << endl;
    }
};

class Teacher : public Person, public Employee
{
public:
    void teach()
    {
        cout << "I teach students" << endl;
    }
};

// ========= MAIN FUNCTION =========
int main()
{
    Shape *s;
    Circle c;
    Rectangle r;

    s = &c;
    s->area();
    s = &r;
    s->area();

    Car car;
    car.start();
    car.horn();
    car.horn(3);

    Puppy p;
    p.sound();

    Teacher t;
    t.info();
    t.job();
    t.teach();

    return 0;
}
