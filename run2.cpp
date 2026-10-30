#include <iostream>

using namespace std;

class Employee
{
private:
    string Name;
    string CompanyName;
    int Age;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setCompanyName(string companyName)
    {
        CompanyName = companyName;
    }
    string getCompanyName()
    {
        return CompanyName;
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
        cout << "name = " << Name << endl;
        cout << "company name = " << CompanyName << endl;
        cout << "age = " << Age << endl;
    }

    Employee(string name, string companyName, int age)
    {
        Name = name;
        CompanyName = companyName;
        Age = age;
    }
};

class Developer : Employee
{
public:
    string FavProgrammingLanguage;

    Developer(string name, string companyName, int age, string Favprogramminglanguage)
        : Employee(name, companyName, age)
    {
        FavProgrammingLanguage = Favprogramminglanguage;
    }

    void fixBug()
    {
        cout << getName() << "fixes his bugs using " << FavProgrammingLanguage << ".\n";
    }
};

int main()
{
    Employee employee1 = Employee("Sam", "Safcom", 12);
    employee1.introduceYourself();

    Developer dev1 = Developer("Simon", "pub industries", 33, "c");
    dev1.fixBug();
}