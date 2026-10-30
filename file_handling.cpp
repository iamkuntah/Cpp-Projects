#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    cout << "File handling example in C++" << endl;

    // Writing to a file
    ofstream outFile("example.txt");
    if (outFile.is_open())
    {
        outFile << "Hello, World!" << endl;
        outFile << "This is a file handling example." << endl;
        outFile.close();
        cout << "Data written to file successfully." << endl;
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }

    // Reading from a file
    ifstream inFile("example.txt");
    if (inFile.is_open())
    {
        string line;
        cout << "\nContents of the file:" << endl;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file for reading." << endl;
    }

    return 0;
}
