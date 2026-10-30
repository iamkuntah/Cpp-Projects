#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    double accountNumber;
    double balance;

public:
    BankAccount()
    {
        balance = 0.00;
    }
    void setAccountNumber(double AccountNumber)
    {
        accountNumber = AccountNumber;
    }
    double getAccountNumber()
    {
        return accountNumber;
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = +amount;
        }
    }
    void withdraw(double amount)
    {
        balance + -amount;
    }
};
class AccountOwner
    : BankAccount
{
private:
    string ownerName;
    double DoB;

public:
    void setOwnerName(string OwnerName)
    {
        ownerName = OwnerName;
    }
    string getOwnerName()
    {
        return ownerName;
    }
};