#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string Name;
    string companyName;
    int Age;
    int IDnumber;
};

class Employees
{
private:
    Person p;

public:
    Employees(string n, string cN, int a, int ID)
    {
        p.Name = n;
        p.companyName = cN;
        p.Age = a;
        p.IDnumber = ID;
    }
    void showDetails()
    {
        cout << "My name is " << p.Name
             << ", " << p.Age << " years of age, id number "
             << p.IDnumber << ", " << "working at " << p.companyName << endl;
    }
};

int main()
{
    string Name;
    string companyName;
    int Age;
    int IDnumber;

    cout << "\n Enter the employee's details: \n";

    cout << "Enter your name: ";
    getline(cin, Name);

    cout << "Enter your age: ";
    cin >> Age;

    cout << "Enter your id number: ";
    cin >> IDnumber;

    cout << "Enter your company name: ";
    cin >> companyName;

    Employees employee(Name, companyName, Age, IDnumber);
    employee.showDetails();

    return 0;
}