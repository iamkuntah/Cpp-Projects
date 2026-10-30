#include <iostream>
#include <string>

using namespace std;

class IFly
{
public:
    virtual void fly() = 0;
    virtual ~IFly() {}
};

class Bird : public IFly
{
public:
    void fly() override
    {
        cout << "Bird is flying high!\n";
    }
};

int main()
{
    Bird b;
    b.fly();
}