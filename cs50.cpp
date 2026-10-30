#include <iostream>

using namespace std;

class Animal
{
public:
    void animalSound()
    {
        cout << "Waaaaah";
    }
};

class Dog
{
public:
    void bark()
    {
        cout << "woof!";
    }
};

int main()
{
    Dog d;
    d.bark();

    Animal chick;
    chick.animalSound();
}