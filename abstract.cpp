#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;

    void sleep()
    {
        cout << "sleeping...\n";
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Woof!\n";
    }
};

int main()
{
    Dog d;
    d.sleep();
    d.makeSound();
}
