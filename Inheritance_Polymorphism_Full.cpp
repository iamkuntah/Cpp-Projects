#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================================
// 1. HIERARCHICAL INHERITANCE EXAMPLE
// ============================================================================
// Base class for shapes (used in hierarchical inheritance)
class Shape
{
protected:
    string name;

public:
    Shape(string n = "Shape") : name(n) {}

    // Virtual function for runtime polymorphism (Method Overriding)
    virtual void calculateArea() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

// Circle class - derives from Shape (Hierarchical)
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void calculateArea() const override
    {
        double area = 3.14159 * radius * radius;
        cout << "\nCircle Area: " << fixed << setprecision(2) << area << endl;
    }

    void display() const override
    {
        cout << "Shape: " << name << " | Radius: " << radius << endl;
    }
};

// Rectangle class - derives from Shape (Hierarchical)
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}

    void calculateArea() const override
    {
        double area = length * width;
        cout << "\nRectangle Area: " << fixed << setprecision(2) << area << endl;
    }

    void display() const override
    {
        cout << "Shape: " << name << " | Length: " << length
             << " | Width: " << width << endl;
    }
};

// ============================================================================
// 2. SINGLE INHERITANCE EXAMPLE
// ============================================================================
// Base class for vehicles (used in single inheritance)
class Vehicle
{
protected:
    string vehicleName;
    string color;
    double speed;

public:
    Vehicle(string name, string col, double spd)
        : vehicleName(name), color(col), speed(spd) {}

    // Virtual function for runtime polymorphism
    virtual void start() const
    {
        cout << "\n"
             << vehicleName << " is starting..." << endl;
    }

    virtual void accelerate() const
    {
        cout << vehicleName << " is accelerating at " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

// Car class - Single inheritance from Vehicle
class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(string name, string col, double spd, int doors)
        : Vehicle(name, col, spd), numberOfDoors(doors) {}

    // Overriding virtual functions (Runtime Polymorphism)
    void start() const override
    {
        cout << "\nCar '" << vehicleName << "' (Color: " << color
             << ", Doors: " << numberOfDoors << ") is starting with engine sound!" << endl;
    }

    void accelerate() const override
    {
        cout << "Car is accelerating smoothly at " << speed << " km/h" << endl;
    }

    // Compile-time polymorphism - Method Overloading
    void honk() const
    {
        cout << "Beep! Beep!" << endl;
    }

    void honk(int times) const
    {
        cout << "Horn: ";
        for (int i = 0; i < times; i++)
        {
            cout << "Beep ";
        }
        cout << endl;
    }
};

// ============================================================================
// 3. MULTILEVEL INHERITANCE EXAMPLE
// ============================================================================
// Base class
class Animal
{
protected:
    string species;
    int age;

public:
    Animal(string sp, int a) : species(sp), age(a) {}

    virtual void eat() const
    {
        cout << "\n"
             << species << " is eating..." << endl;
    }

    virtual void sleep() const
    {
        cout << species << " is sleeping..." << endl;
    }

    virtual ~Animal() {}
};

// Intermediate class inheriting from Animal (Level 1)
class Dog : public Animal
{
protected:
    string breed;

public:
    Dog(string sp, int a, string b) : Animal(sp, a), breed(b) {}

    void eat() const override
    {
        cout << "\nDog (Breed: " << breed << ") is eating dog food..." << endl;
    }

    void bark() const
    {
        cout << "Woof! Woof!" << endl;
    }

    virtual ~Dog() {}
};

// Final derived class inheriting from Dog (Level 2 - Multilevel)
class GoldenRetriever : public Dog
{
private:
    string color;

public:
    GoldenRetriever(string sp, int a, string b, string c)
        : Dog(sp, a, b), color(c) {}

    void eat() const override
    {
        cout << "\nGolden Retriever (Color: " << color
             << ") is eating with enthusiasm..." << endl;
    }

    void fetch() const
    {
        cout << "Golden Retriever is fetching the ball happily!" << endl;
    }

    // Compile-time polymorphism - Method Overloading
    void play() const
    {
        cout << "Playing with toys" << endl;
    }

    void play(string toyName) const
    {
        cout << "Playing with " << toyName << endl;
    }

    void play(string toyName, int duration) const
    {
        cout << "Playing with " << toyName << " for " << duration << " minutes" << endl;
    }
};

// ============================================================================
// 4. MULTIPLE INHERITANCE EXAMPLE
// ============================================================================
// First base class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void introduce() const
    {
        cout << "\nHello, I am " << name << ", age " << age << endl;
    }

    virtual ~Person() {}
};

// Second base class
class Employee
{
protected:
    string employeeID;
    double salary;

public:
    Employee(string id, double sal) : employeeID(id), salary(sal) {}

    virtual void workDetails() const
    {
        cout << "Employee ID: " << employeeID << " | Salary: $" << salary << endl;
    }

    virtual ~Employee() {}
};

// Teacher class - Multiple inheritance from Person and Employee
class Teacher : public Person, public Employee
{
private:
    string subject;
    int yearsOfExperience;

public:
    Teacher(string n, int a, string id, double sal, string subj, int yoe)
        : Person(n, a), Employee(id, sal), subject(subj), yearsOfExperience(yoe) {}

    // Overriding virtual functions from Person
    void introduce() const override
    {
        cout << "\nHello, I am " << name << ", age " << age
             << ", a teacher of " << subject << endl;
    }

    // Overriding virtual functions from Employee
    void workDetails() const override
    {
        cout << "Employee ID: " << employeeID << " | Salary: $" << salary
             << " | Experience: " << yearsOfExperience << " years" << endl;
    }

    // Compile-time polymorphism - Method Overloading
    void teach() const
    {
        cout << "Teaching " << subject << " class" << endl;
    }

    void teach(int numStudents) const
    {
        cout << "Teaching " << subject << " to " << numStudents << " students" << endl;
    }

    void teach(int numStudents, int duration) const
    {
        cout << "Teaching " << subject << " to " << numStudents
             << " students for " << duration << " hours" << endl;
    }
};

// ============================================================================
// MAIN FUNCTION - Command Line User Interface
// ============================================================================
int main()
{
    cout << "============================================" << endl;
    cout << "C++ INHERITANCE AND POLYMORPHISM DEMO" << endl;
    cout << "============================================" << endl;

    int choice;
    bool running = true;

    while (running)
    {
        cout << "\n\nMain Menu:" << endl;
        cout << "1. Hierarchical Inheritance (Shapes)" << endl;
        cout << "2. Single Inheritance (Vehicles)" << endl;
        cout << "3. Multilevel Inheritance (Animals)" << endl;
        cout << "4. Multiple Inheritance (Teacher)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        // ========== HIERARCHICAL INHERITANCE ==========
        case 1:
        {
            cout << "\n--- HIERARCHICAL INHERITANCE DEMO ---" << endl;
            cout << "Shapes derived from base class Shape" << endl;

            Circle circle(5.0);
            Rectangle rectangle(4.0, 6.0);

            cout << "\n[Shape 1]" << endl;
            circle.display();
            circle.calculateArea();

            cout << "\n[Shape 2]" << endl;
            rectangle.display();
            rectangle.calculateArea();

            cout << "\nDemonstrating Runtime Polymorphism (Virtual Functions):" << endl;
            Shape *shape1 = &circle;
            Shape *shape2 = &rectangle;
            cout << "\nCalling through base class pointers:" << endl;
            shape1->display();
            shape1->calculateArea();
            shape2->display();
            shape2->calculateArea();
            break;
        }

        // ========== SINGLE INHERITANCE ==========
        case 2:
        {
            cout << "\n--- SINGLE INHERITANCE DEMO ---" << endl;
            cout << "Car class derived from Vehicle class" << endl;

            Car myCar("Tesla", "Red", 150, 4);

            cout << "\n[Car Operations]" << endl;
            myCar.start();
            myCar.accelerate();

            cout << "\n[Compile-time Polymorphism - Method Overloading]" << endl;
            cout << "Honk without parameter:" << endl;
            myCar.honk();

            cout << "Honk with parameter (5 times):" << endl;
            myCar.honk(5);

            cout << "\n[Runtime Polymorphism - Through base class pointer]" << endl;
            Vehicle *vehicle = &myCar;
            vehicle->start();
            vehicle->accelerate();
            break;
        }

        // ========== MULTILEVEL INHERITANCE ==========
        case 3:
        {
            cout << "\n--- MULTILEVEL INHERITANCE DEMO ---" << endl;
            cout << "GoldenRetriever -> Dog -> Animal" << endl;

            GoldenRetriever myDog("Canine", 3, "Golden Retriever", "Golden");

            cout << "\n[Dog Operations - From multilevel hierarchy]" << endl;
            myDog.eat();
            myDog.bark();
            myDog.sleep();
            myDog.fetch();

            cout << "\n[Compile-time Polymorphism - Method Overloading]" << endl;
            cout << "Play without parameters:" << endl;
            myDog.play();

            cout << "Play with toy name:" << endl;
            myDog.play("Tennis Ball");

            cout << "Play with toy name and duration:" << endl;
            myDog.play("Frisbee", 30);
            break;
        }

        // ========== MULTIPLE INHERITANCE ==========
        case 4:
        {
            cout << "\n--- MULTIPLE INHERITANCE DEMO ---" << endl;
            cout << "Teacher class inherits from both Person and Employee" << endl;

            Teacher teacher("Mr. John", 35, "EMP001", 50000, "Mathematics", 10);

            cout << "\n[Multiple Inheritance - Accessing both base classes]" << endl;
            teacher.introduce();
            teacher.workDetails();

            cout << "\n[Compile-time Polymorphism - Method Overloading]" << endl;
            cout << "Teach without parameters:" << endl;
            teacher.teach();

            cout << "Teach with number of students:" << endl;
            teacher.teach(30);

            cout << "Teach with students and duration:" << endl;
            teacher.teach(30, 2);
            break;
        }

        // ========== EXIT ==========
        case 5:
        {
            cout << "\nThank you for exploring Inheritance and Polymorphism!" << endl;
            running = false;
            break;
        }

        default:
        {
            cout << "\nInvalid choice! Please enter 1-5." << endl;
        }
        }
    }

    return 0;
}

/*
================================================================================
SUMMARY OF CONCEPTS DEMONSTRATED
================================================================================

1. HIERARCHICAL INHERITANCE (Case 1):
   - Base class: Shape
   - Derived classes: Circle, Rectangle
   - Both inherit from the same base class
   - Runtime Polymorphism: Virtual functions (calculateArea, display)

2. SINGLE INHERITANCE (Case 2):
   - Base class: Vehicle
   - Derived class: Car
   - Car inherits all properties and methods from Vehicle
   - Compile-time Polymorphism: Overloaded honk() method
   - Runtime Polymorphism: Virtual functions (start, accelerate)

3. MULTILEVEL INHERITANCE (Case 3):
   - Level 1 Base: Animal
   - Level 2 Derived: Dog (inherits from Animal)
   - Level 3 Derived: GoldenRetriever (inherits from Dog)
   - Forms a chain: GoldenRetriever -> Dog -> Animal
   - Compile-time Polymorphism: Overloaded play() method
   - Runtime Polymorphism: Virtual functions

4. MULTIPLE INHERITANCE (Case 4):
   - Base classes: Person and Employee
   - Derived class: Teacher
   - Teacher inherits from both Person and Employee
   - Compile-time Polymorphism: Overloaded teach() method
   - Runtime Polymorphism: Virtual functions from both base classes

POLYMORPHISM TYPES:
- Compile-time: Method Overloading (same function name, different parameters)
  Examples: honk(), play(), teach()
- Runtime: Method Overriding (virtual functions, using override keyword)
  Examples: start(), eat(), introduce()

================================================================================
*/
