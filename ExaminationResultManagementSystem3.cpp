#include <iostream>
#include <string>

using namespace std;

class student
{
private:
    string Name;
    string admissionNumber;
    int idNumber;

public:
    string getName()
    {
        return Name;
    }
    string getAdm()
    {
        return admissionNumber;
    }
    int getId()
    {
        return idNumber;
    }

    student(string n, string adm, int id)
    {
        Name = n;
        admissionNumber = adm;
        idNumber = id;
    }

    void displayInfo()
    {
        cout << "Name: " << Name << "\n";
        cout << "Admission nunber: " << admissionNumber << "\n";
        cout << "ID Number: " << idNumber << "\n";
    }
};
class examSystem
{
    int marks;

    char calculateGrade()
    {
        if (marks >= 80)
        {
        }
    }
};