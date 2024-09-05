// 5.3: Modify the class and the program of Exercise 5.1 for handling 10 customers
#include <iostream>
#include <iomanip>
#include <cstring>
#define SIZE 10
using namespace std;

// Array of serial numbers for customers
const char *serial[SIZE] = {"FIRST", "SECOND", "THIRD", "FOURTH", "FIFTH", "SIXTH", "SEVENTH", "EIGHTH", "NINTH", "TENTH"};

class Bank
{
    char name[40];
    int ac_no;
    char ac_type[20];
    double balance;

public:
    int assign();
    void deposit(float b);
    void withdraw(float c);
    void display_on() const;
    void display_off() const;
};

// Function to create a new account
int Bank::assign()
{
    float initial;
    cout << " You have to pay 500 TK to open your account\n"
         << " You have to store at least 500 TK to keep your account active\n"
         << "Would you like to open an account?\n"
         << " If Yes, press 1\n"
         << " If No, press 0: ";
    int test;
    cin >> test;

    if (test == 1)
    {
        initial = 500;
        balance = initial;
        cout << " Enter name, account number, and account type to create an account: \n";
        cin >> name >> ac_no >> ac_type;
    }
    return test;
}

// Function to deposit money
void Bank::deposit(float b)
{
    balance += b;
}

// Function to withdraw money
void Bank::withdraw(float c)
{
    if (balance - c < 500)
    {
        cout << " Sorry, your balance is insufficient to withdraw " << c << " TK\n"
             << " You must maintain a minimum of 500 TK to keep your account active.\n";
    }
    else
    {
        balance -= c;
    }
}

// Function to display account details
void Bank::display_on() const
{
    cout << setw(12) << name << setw(17) << ac_type << setw(14) << balance << endl;
}

// Function to display message for accounts that were not created
void Bank::display_off() const
{
    cout << "Account was not created." << endl;
}

int main()
{
    Bank account[SIZE];
    int t[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << " Enter information for the " << serial[i] << " customer: " << endl;
        t[i] = account[i].assign();

        if (t[i] == 1)
        {
            // Deposit process
            cout << " Would you like to deposit? (Enter deposit amount or 0 to skip): ";
            float dp;
            cin >> dp;
            if (dp > 0)
            {
                account[i].deposit(dp);
            }

            // Withdraw process
            cout << " Would you like to withdraw? (Enter withdrawal amount or 0 to skip): ";
            float wd;
            cin >> wd;
            if (wd > 0)
            {
                account[i].withdraw(wd);
            }

            cout << endl;
        }
        else if (t[i] == 0)
        {
            cout << "Thank you, see you again!\n";
        }
    }

    // Display customer details
    cout << "Account details:\n";
    cout << setw(12) << "Name" << setw(20) << "Account Type" << setw(12) << "Balance" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (t[i] == 1)
        {
            account[i].display_on();
        }
        else if (t[i] == 0)
        {
            account[i].display_off();
        }
    }

    return 0;
}
