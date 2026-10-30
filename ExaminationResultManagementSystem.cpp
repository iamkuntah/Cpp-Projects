#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Abstract Base Class - Abstraction
class ExamResult
{
protected:
    int rollNumber;
    string studentName;
    int totalMarks;
    int obtainedMarks;

public:
    ExamResult(int roll, string name, int total, int obtained) // examResult constructor
    {
        roll = rollNumber;
        name = studentName;
        total = totalMarks;
        obtained = obtainedMarks;
    }

    virtual ~ExamResult() {}

    // Pure virtual functions - Abstraction & Polymorphism
    virtual double calculatePercentage() = 0;
    virtual char calculateGrade() = 0;
    virtual void display() = 0;
    virtual string getResultDetails() = 0;

    // Getters - Encapsulation
    int getRollNumber() const { return rollNumber; }
    string getStudentName() const { return studentName; }
    int getObtainedMarks() const { return obtainedMarks; }
    int getTotalMarks() const { return totalMarks; }
};

// Derived Class 1 - Inheritance
class SemesterExam : public ExamResult
{
private:
    int semester;
    string subject;

public:
    SemesterExam(int roll, string name, int total, int obtained, int sem, string subj)
        : ExamResult(roll, name, total, obtained), semester(sem), subject(subj) {}

    // Polymorphism - Override virtual functions
    double calculatePercentage() override
    {
        return (obtainedMarks * 100.0) / totalMarks;
    }

    char calculateGrade() override
    {
        double percentage = calculatePercentage();
        if (percentage >= 90)
            return 'A';
        else if (percentage >= 80)
            return 'B';
        else if (percentage >= 70)
            return 'C';
        else if (percentage >= 60)
            return 'D';
        else
            return 'F';
    }

    void display() override
    {
        cout << "\n--- Semester Exam Result ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << studentName << endl;
        cout << "Semester: " << semester << endl;
        cout << "Subject: " << subject << endl;
        cout << "Marks: " << obtainedMarks << "/" << totalMarks << endl;
        cout << "Percentage: " << fixed << setprecision(2) << calculatePercentage() << "%" << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }

    string getResultDetails() override
    {
        return to_string(rollNumber) + "," + studentName + "," + to_string(semester) + "," + subject + "," + to_string(obtainedMarks) + "," + to_string(totalMarks) + "," + to_string(calculatePercentage()) + "," + calculateGrade();
    }
};

// Derived Class 2 - Inheritance
class MidtermExam : public ExamResult
{
private:
    string examDate;
    string duration;

public:
    MidtermExam(int roll, string name, int total, int obtained, string date, string dur)
        : ExamResult(roll, name, total, obtained), examDate(date), duration(dur) {}

    // Polymorphism - Override virtual functions
    double calculatePercentage() override
    {
        return (obtainedMarks * 100.0) / totalMarks;
    }

    char calculateGrade() override
    {
        double percentage = calculatePercentage();
        if (percentage >= 85)
            return 'A';
        else if (percentage >= 75)
            return 'B';
        else if (percentage >= 65)
            return 'C';
        else if (percentage >= 55)
            return 'D';
        else
            return 'F';
    }

    void display() override
    {
        cout << "\n--- Midterm Exam Result ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << studentName << endl;
        cout << "Date: " << examDate << endl;
        cout << "Duration: " << duration << endl;
        cout << "Marks: " << obtainedMarks << "/" << totalMarks << endl;
        cout << "Percentage: " << fixed << setprecision(2) << calculatePercentage() << "%" << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }

    string getResultDetails() override
    {
        return to_string(rollNumber) + "," + studentName + "," + examDate + "," + duration + "," + to_string(obtainedMarks) + "," + to_string(totalMarks) + "," + to_string(calculatePercentage()) + "," + calculateGrade();
    }
};

// Derived Class 3 - Inheritance
class FinalExam : public ExamResult
{
private:
    string examType;
    string passStatus;

public:
    FinalExam(int roll, string name, int total, int obtained, string type)
        : ExamResult(roll, name, total, obtained), examType(type)
    {
        passStatus = (calculatePercentage() >= 40) ? "PASS" : "FAIL";
    }

    // Polymorphism - Override virtual functions
    double calculatePercentage() override
    {
        return (obtainedMarks * 100.0) / totalMarks;
    }

    char calculateGrade() override
    {
        double percentage = calculatePercentage();
        if (percentage >= 90)
            return 'A';
        else if (percentage >= 80)
            return 'B';
        else if (percentage >= 70)
            return 'C';
        else if (percentage >= 60)
            return 'D';
        else if (percentage >= 40)
            return 'E';
        else
            return 'F';
    }

    void display() override
    {
        cout << "\n--- Final Exam Result ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << studentName << endl;
        cout << "Exam Type: " << examType << endl;
        cout << "Marks: " << obtainedMarks << "/" << totalMarks << endl;
        cout << "Percentage: " << fixed << setprecision(2) << calculatePercentage() << "%" << endl;
        cout << "Grade: " << calculateGrade() << endl;
        cout << "Status: " << passStatus << endl;
    }

    string getResultDetails() override
    {
        return to_string(rollNumber) + "," + studentName + "," + examType + "," + to_string(obtainedMarks) + "," + to_string(totalMarks) + "," + to_string(calculatePercentage()) + "," + calculateGrade() + "," + passStatus;
    }
};

// Management System Class - Encapsulation
class ResultManagementSystem
{
private:
    vector<ExamResult *> results;
    string filename;

    // Private helper methods - Encapsulation
    void saveToFile()
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            for (auto result : results)
            {
                file << result->getResultDetails() << endl;
            }
            file.close();
            cout << "\nData saved to file successfully!" << endl;
        }
        else
        {
            cerr << "Error: Could not open file!" << endl;
        }
    }

public:
    ResultManagementSystem(string fname = "examination_results.txt") : filename(fname) {}

    ~ResultManagementSystem()
    {
        for (auto result : results)
        {
            delete result;
        }
        results.clear();
    }

    // Public methods - Encapsulation
    void addSemesterExam(int roll, string name, int total, int obtained, int sem, string subject)
    {
        results.push_back(new SemesterExam(roll, name, total, obtained, sem, subject));
        cout << "Semester exam result added successfully!" << endl;
    }

    void addMidtermExam(int roll, string name, int total, int obtained, string date, string duration)
    {
        results.push_back(new MidtermExam(roll, name, total, obtained, date, duration));
        cout << "Midterm exam result added successfully!" << endl;
    }

    void addFinalExam(int roll, string name, int total, int obtained, string type)
    {
        results.push_back(new FinalExam(roll, name, total, obtained, type));
        cout << "Final exam result added successfully!" << endl;
    }

    void displayAllResults()
    {
        if (results.empty())
        {
            cout << "\nNo results available!" << endl;
            return;
        }

        cout << "\n========================================" << endl;
        cout << "    ALL EXAMINATION RESULTS" << endl;
        cout << "========================================" << endl;

        for (auto result : results)
        {
            result->display();
        }
    }

    void displayResultByRoll(int roll)
    {
        bool found = false;
        for (auto result : results)
        {
            if (result->getRollNumber() == roll)
            {
                result->display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "\nNo result found for roll number: " << roll << endl;
        }
    }

    void displayResultByName(string name)
    {
        bool found = false;
        for (auto result : results)
        {
            if (result->getStudentName() == name)
            {
                result->display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "\nNo result found for student: " << name << endl;
        }
    }

    void displayTopPerformer()
    {
        if (results.empty())
        {
            cout << "\nNo results available!" << endl;
            return;
        }

        ExamResult *topResult = results[0];
        for (auto result : results)
        {
            if (result->calculatePercentage() > topResult->calculatePercentage())
            {
                topResult = result;
            }
        }

        cout << "\n--- Top Performer ---" << endl;
        cout << "Name: " << topResult->getStudentName() << endl;
        cout << "Roll Number: " << topResult->getRollNumber() << endl;
        cout << "Percentage: " << fixed << setprecision(2) << topResult->calculatePercentage() << "%" << endl;
    }

    void calculateAveragePercentage()
    {
        if (results.empty())
        {
            cout << "\nNo results available!" << endl;
            return;
        }

        double totalPercentage = 0;
        for (auto result : results)
        {
            totalPercentage += result->calculatePercentage();
        }

        double average = totalPercentage / results.size();
        cout << "\nAverage Percentage of All Students: " << fixed << setprecision(2) << average << "%" << endl;
    }

    void saveResultsToFile()
    {
        saveToFile();
    }

    void loadResultsFromFile()
    {
        ifstream file(filename);
        if (file.is_open())
        {
            cout << "\nFile loaded: " << filename << endl;
            file.close();
        }
        else
        {
            cout << "\nFile does not exist yet. It will be created when you save results." << endl;
        }
    }

    int getTotalResults()
    {
        return results.size();
    }
};

// Main function - Demonstration
int main()
{
    ResultManagementSystem system;
    int choice;

    cout << "\n========================================" << endl;
    cout << "  EXAMINATION RESULT MANAGEMENT SYSTEM" << endl;
    cout << "========================================\n"
         << endl;

    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Add Semester Exam Result" << endl;
        cout << "2. Add Midterm Exam Result" << endl;
        cout << "3. Add Final Exam Result" << endl;
        cout << "4. Display All Results" << endl;
        cout << "5. Search Result by Roll Number" << endl;
        cout << "6. Search Result by Name" << endl;
        cout << "7. Display Top Performer" << endl;
        cout << "8. Calculate Average Percentage" << endl;
        cout << "9. Save Results to File" << endl;
        cout << "10. Load Results from File" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            int roll, total, obtained, sem;
            string name, subject;

            cout << "\n--- Add Semester Exam Result ---" << endl;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Total Marks: ";
            cin >> total;
            cout << "Enter Obtained Marks: ";
            cin >> obtained;
            cout << "Enter Semester: ";
            cin >> sem;
            cin.ignore();
            cout << "Enter Subject: ";
            getline(cin, subject);

            system.addSemesterExam(roll, name, total, obtained, sem, subject);
            break;
        }

        case 2:
        {
            int roll, total, obtained;
            string name, date, duration;

            cout << "\n--- Add Midterm Exam Result ---" << endl;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Total Marks: ";
            cin >> total;
            cout << "Enter Obtained Marks: ";
            cin >> obtained;
            cin.ignore();
            cout << "Enter Exam Date (DD-MM-YYYY): ";
            getline(cin, date);
            cout << "Enter Duration (e.g., 2 hours): ";
            getline(cin, duration);

            system.addMidtermExam(roll, name, total, obtained, date, duration);
            break;
        }

        case 3:
        {
            int roll, total, obtained;
            string name, type;

            cout << "\n--- Add Final Exam Result ---" << endl;
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Total Marks: ";
            cin >> total;
            cout << "Enter Obtained Marks: ";
            cin >> obtained;
            cin.ignore();
            cout << "Enter Exam Type (Theory/Practical): ";
            getline(cin, type);

            system.addFinalExam(roll, name, total, obtained, type);
            break;
        }

        case 4:
            system.displayAllResults();
            break;

        case 5:
        {
            int roll;
            cout << "\nEnter Roll Number to search: ";
            cin >> roll;
            system.displayResultByRoll(roll);
            break;
        }

        case 6:
        {
            string name;
            cout << "\nEnter Student Name to search: ";
            cin.ignore();
            getline(cin, name);
            system.displayResultByName(name);
            break;
        }

        case 7:
            system.displayTopPerformer();
            break;

        case 8:
            system.calculateAveragePercentage();
            break;

        case 9:
            system.saveResultsToFile();
            break;

        case 10:
            system.loadResultsFromFile();
            break;

        case 11:
            cout << "\nThank you for using Examination Result Management System!" << endl;
            break;

        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 11);

    return 0;
}
