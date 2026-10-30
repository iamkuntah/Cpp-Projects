#include <iostream>
#include <string>

using namespace std;

class AbstractPromotion
{
public:
    virtual void askForPromotion() = 0;
};
class Employee : public AbstractPromotion
{
private:
    string Name;
    int Age;
    string companyName;

public:
    void setName(string n)
    {
        Name = n;
    }
    string getName()
    {
        return Name;
    }
    void setAge(int a)
    {
        Age = a;
    }
    int getAge()
    {
        return Age;
    }
    void setCompanyName(string company)
    {
        companyName = company;
    }
    string getCompanyName()
    {
        return companyName;
    }

    Employee(string n, int a, string company)
    {
        Name = n;
        Age = a;
        companyName = company;
    }

    void askForPromotion()
    {
        if (Age < 19)
        {
            cout << Name << " You're not getting a promoton this time!" << endl;
        }
        else
        {
            cout << Name << " You are promoted!" << endl;
        }
    }

    void introduceYourself()
    {
        cout << "My name is " << Name << "\n";
        cout << "I'm " << Age << " years of age \n";
        cout << "I work at " << companyName << ".\n";
    }
};

int main()
{
    Employee employee1("Sam araka", 20, "Virtual studios");

    employee1.introduceYourself();
    employee1.askForPromotion();

    return 0;
}