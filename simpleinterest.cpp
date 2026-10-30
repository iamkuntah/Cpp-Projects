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
        cout << "My name is " << Name << ".\n";
        cout << "Company name is " << CompanyName << ".\n";
        cout << "My age is " << Age << ".\n";
    }

    Employee(string name, string companyName, int age) // constructor
    {
        Name = name;
        CompanyName = companyName;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Sam Araka", "Coding YT", 21);
    employee1.introduceYourself();

    employee1.setAge(22);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl; // test to see if the getters and setters are working as purposed.

    Employee employee2 = Employee("Cladius Obure", "Fishing company", 33);
    employee2.introduceYourself();

    Employee employee3 = Employee("Cladius Obure2", "Fishing company", 23);
    employee3.introduceYourself();
}