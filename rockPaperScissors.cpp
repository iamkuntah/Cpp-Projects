#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // seed random number

    int userChoice;
    int computerChoice;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << " 1.Rock.\n 2.Paper.\n 3.Scissors.\n";

    cout << "Enter your choice (1/ 2/ 3):" << endl;
    cin >> userChoice;

    computerChoice = rand() % 3 + 1;
    // Generate a random number between 1 and 3

    cout << "Computer chose: " << computerChoice << endl;
    // compare choice

    if (userChoice == computerChoice)
    {
        cout << "It;s a draw! " << endl;
    }
    else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
    {
        cout << "You Win!" << endl;
    }
    else
    {
        cout << "You lose!" << endl;
    }

    return 0;
}