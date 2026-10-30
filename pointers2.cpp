#include <iostream>
using namespace std;

void printNumber(int *numberPtr)
{
    cout << *numberPtr << endl;
}

int main()
{
    int number = 5;
    printNumber(&number);
    return 0;
}