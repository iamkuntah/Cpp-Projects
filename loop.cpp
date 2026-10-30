#include <iostream>
#include <iostream>

using namespace std;

void printAll(void *ptr, char type)
{
    switch (type)
    {
    case 'i':
    {
        cout << *((int *)ptr) << "\n";
        break;
    }
    case 'c':
    {
        cout << *((char *)ptr) << endl;
        break;
    }
    case 'f':
    {
        cout << *((float *)ptr) << "\n";
        break;
    }
    default:
    {
        cout << "Wacha Ufala Walai!!" << endl;
        break;
    }
    }
}

int main()
{
    int number = 5;
    char alphabet = 'a';

    printAll(&number, 'i');
    printAll(&alphabet, 'c');
}