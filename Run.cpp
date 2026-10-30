#include <iostream>

using namespace std;

class Employee
{
private:
    string Name;
    string Company;
    int Age;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

    void setCompany(string company)
    {
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        Age = age;
    }

    int getAge()
    {
        return Age;
    }

    void introduceYourself()
    {
        cout << "name = " << Name << ".\n";
        cout << "company = " << Company << ".\n";
        cout << "age = " << Age << ".\n";
    }
};