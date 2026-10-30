#include <iostream>
using namespace std;

// 1. HIERARCHICAL INHERITANCE
class Shape
{
public:
    virtual void display() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void display() { cout << "Circle with radius 5\n"; }
};

class Rectangle : public Shape
{
public:
    void display() { cout << "Rectangle 4x6\n"; }
};

// 2. SINGLE INHERITANCE
class Vehicle
{
public:
    virtual void start() { cout << "Vehicle starting\n"; }
};

class Car : public Vehicle
{
public:
    void start() { cout << "Car starting with engine\n"; }
    void honk() { cout << "Beep!\n"; }
    void honk(int n)
    {
        for (int i = 0; i < n; i++)
            cout << "Beep ";
        cout << "\n";
    }
};

// 3. MULTILEVEL INHERITANCE
class Animal
{
public:
    virtual void eat() { cout << "Eating...\n"; }
};

class Dog : public Animal
{
public:
    void eat() { cout << "Dog eating\n"; }
    void bark() { cout << "Woof!\n"; }
};

class GoldenRetriever : public Dog
{
public:
    void eat() { cout << "Golden Retriever eating\n"; }
    void fetch() { cout << "Fetching ball\n"; }
    void play() { cout << "Playing\n"; }
    void play(string toy) { cout << "Playing with " << toy << "\n"; }
};

// 4. MULTIPLE INHERITANCE
class Person
{
protected:
    string name;

public:
    Person(string n) : name(n) {}
    virtual void info() { cout << "Person: " << name << "\n"; }
};

class Employee
{
protected:
    string empID;

public:
    Employee(string id) : empID(id) {}
    virtual void work() { cout << "Employee ID: " << empID << "\n"; }
};

class Teacher : public Person, public Employee
{
private:
    string subject;

public:
    Teacher(string n, string id, string s) : Person(n), Employee(id), subject(s) {}
    void teach() { cout << "Teaching " << subject << "\n"; }
    void teach(int students) { cout << "Teaching " << students << " students\n"; }
    void info() { cout << "Teacher " << name << " teaches " << subject << "\n"; }
};

int main()
{
    Circle c;
    Rectangle r;
    c.display();
    r.display();

    Car car;
    car.honk();
    car.honk(3);

    GoldenRetriever dog;
    dog.eat();
    dog.fetch();
    dog.play();
    dog.play("Tennis Ball");

    Teacher teacher("John", "EMP001", "Math");
    teacher.info();
    teacher.teach();
    teacher.teach(30);

    return 0;
}
