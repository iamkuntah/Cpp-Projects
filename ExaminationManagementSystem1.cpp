#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
protected:
    string Name;
    int idNumber;

public:
    Person(string name, int id)
    {
        Name = name;
        idNumber = id;
    }

    virtual void displayInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "ID number: " << idNumber << endl;
    }

    string getName()
    {
        return Name;
    }
    int getId()
    {
        return idNumber;
    }

    virtual ~Person() {}
};
class Student : public Person
{
private:
    string admissionNumber;
    int Marks;

public:
    Student(string name, int id, string adm, int marks)
        : Person(name, id)
    {
        admissionNumber = adm;
        Marks = marks;
    }
    string getAdmissionNumber()
    {
        return admissionNumber;
    }
    int getMarks()
    {
        return Marks;
    }

    char calculateGrade()
    {
        if (Marks >= 70)
        {
            return 'A';
        }
        else if (Marks >= 60)
        {
            return 'B';
        }
        else if (Marks >= 50)
        {
            return 'C';
        }
        else if (Marks >= 40)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    // overriding displayInfo method

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Admission Number: " << admissionNumber << endl;
        cout << "Marks: " << Marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};

class examSystem
{
private:
    vector<Student> Students;

public:
    void addStudent()
    {
        string Name;
        string AdmissionNumber;
        int Marks;
        int id;

        cout << "Enter name: ";

        getline(cin >> ws, Name);

        cout << "Enter your admission number: ";
        cin >> AdmissionNumber;

        cout << "Enter marks: ";
        cin >> Marks;

        cout << "Enter ID number: ";
        cin >> id;

        Student s(Name, id, AdmissionNumber, Marks);
        Students.push_back(s);

        cout << "Student added succesfully!" << endl;
    }

    void displayStudents()
    {
        if (Students.empty())
        {
            cout << "No students found" << endl;
            return;
        }

        for (auto &s : Students)
            s.displayInfo();
    }

    void saveToFile()
    {
        ofstream file("students.txt"); // open file in write.

        if (!file) // check if the file is opened successfully.
        {
            cout << "Error writting in the file!" << endl;
            return;
        }
        for (auto &s : Students) // write each student data in the file.
        {
            file << s.getName() << ","
                 << s.getId() << ","
                 << s.getAdmissionNumber() << ","
                 << s.getMarks() << endl;
        }
        file.close();

        cout << "Data saved successfully!" << endl;
    }

    void loadFromFile()
    {
        ifstream file("students.txt");
        if (!file)
        {
            cout << "No data found!" << endl;
            return;
        }
        Students.clear();

        string Name;
        string AdmissionNumber;
        int Marks;
        int id;
        char comma;

        while (getline(file, Name, ','))
        {
            file >> id >> comma;
            getline(file, AdmissionNumber, ',');
            file >> Marks;
            file.ignore();

            Student s(Name, id, AdmissionNumber, Marks);
            Students.push_back(s);
        }
        file.close();
        cout << "Data loaded successfully!" << endl;
    }
};

// Main function
int main()
{
    examSystem system;
    int choice;

    system.loadFromFile();

    do
    {
        cout << "=== EXAMINATION MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Add student." << endl;
        cout << "2. Display students." << endl;
        cout << "3. Save data." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system.addStudent();
            break;
        }
        case 2:
        {
            system.displayStudents();
            break;
        }
        case 3:
        {
            system.saveToFile();
            break;
        }
        case 0:
        {
            system.saveToFile();
            cout << "Exiting ..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid Character!" << endl;
        }
        }
    } while (choice != 0);

    return 0;
}
