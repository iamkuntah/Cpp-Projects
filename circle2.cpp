#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void bark() = 0;
};

class Dog : public Animal
{
public:
    void bark() override
    {
        cout << "woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void bark() override
    {
        cout << "meow!" << endl;
    }
};

int main()
{
    Animal a1 = new Dog();
    Animal a2 = new Cat();
}