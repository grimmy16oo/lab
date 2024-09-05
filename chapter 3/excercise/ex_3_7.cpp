// 3.7 : Write a program to evaluate the following function to 0.0001% accuracy
/*
    Find the sin(x),cos(x),and sum(x)
    sin(x) = x - x^3/3! + x^5/5! ..
    cos(x) = 1 - x^2/2! + x^4/4!...
    sum(x) = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 +..
*/

#include <iostream>
#include <cmath>
#include <cstdlib> // For exit function

// Define PI constant
#define PI 3.141592654
#define MAX_TERMS 100 // Max number of terms to consider

using namespace std;

// Function to calculate factorial iteratively
int fact(int i)
{
    int f = 1;
    for (int j = 2; j <= i; j++)
    {
        f *= j;
    }
    return f;
}

// Function to calculate the sum series: sum(x) = 1 + (1/2)^2 + (1/3)^3 + ...
double sum()
{
    double sumx = 0;
    for (int i = 1; i <= MAX_TERMS; i++)
    {
        sumx += pow(1.0 / i, i);
    }
    return sumx;
}

// Function to calculate cosine using the series: cos(x) = 1 - x^2/2! + x^4/4! - ...
double cosx(double value)
{
    double cosine = 1.0, term;
    int i = 1;
    do
    {
        term = pow(-1, i) * pow(value, 2 * i) / fact(2 * i);
        cosine += term;
        i++;
    } while (fabs(term) > 0.000001); // Accuracy up to 0.0001%
    return cosine;
}

// Function to calculate sine using the series: sin(x) = x - x^3/3! + x^5/5! - ...
double sinx(double value)
{
    double sine = value, term;
    int i = 1;
    do
    {
        term = pow(-1, i) * pow(value, 2 * i + 1) / fact(2 * i + 1);
        sine += term;
        i++;
    } while (fabs(term) > 0.000001); // Accuracy up to 0.0001%
    return sine;
}

int main()
{
    int choice;
    double no;

    do
    {
        cout << "\nChoose any option:";
        cout << "\n1. Sin(x)\n2. Cos(x)\n3. Sum series\n4. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the value of x in radians: ";
            cin >> no;
            cout << "\nValue of sin(" << no << ") = " << sinx(no) << "\n";
            break;
        case 2:
            cout << "\nEnter the value of x in radians: ";
            cin >> no;
            cout << "\nValue of cos(" << no << ") = " << cosx(no) << "\n";
            break;
        case 3:
            cout << "\nValue of sum = " << sum() << "\n";
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (true);

    return 0;
}
