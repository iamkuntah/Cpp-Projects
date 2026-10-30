#include <iostream>

using namespace std;

class BankAccount
{
private:
    ;
    string ownerName;
    int accountNumber;
    double balance;

public:
    void initialBalance();

    void setownerName(string OwnerName)
    {
        ownerName = OwnerName;
    }

    string getownerName()
    {
        return ownerName;
    }

    void setaccountNumber(int AccountNumber)
    {
        accountNumber = AccountNumber;
    }

    int getaccountNumber()
    {
        return accountNumber;
    }
    BankAccount(int Balance)
    {
        balance = Balance;
    }
};
int main()
{
    int choice;
    double amount;

    cout << "Welcome to your account!!" << endl;

    cout << "1.Deposit.\n";
    cout << "2.Withdraw.\n";
    cout << "3.Quit.\n";
    cout << "Choose either (1, 2, 3):";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        void deposit(double amount);
    }
}

void deposit(double amount)
{
    BankAccount balance = BankAccount(1000);

    cout << "Deposited:" << amount << endl;
    cout << "Balance:" << endl;
}
