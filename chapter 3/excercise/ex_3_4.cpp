/* 3.4 : Write a program to evaluate the following investment equation V = P(1+r)n and print the tables which would give the value of V for various of the following values of P, r and n: P: 1000, 2000, 3000,……………,10,000 r: 0.10, 0.11, 0.12,………………….,0.20 n: 1, 2, 3,…………………………………..,10
(Hint: P is the principal amount and V is the value of money at the end of n years.
This equation can be recursively written as V = P(1 + r) P = V In other words, the value of money at the end of the first year becomes the principal amount for the next year and so on)
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 8

int main()
{
    float v, pf;
    int n = 10;
    float p[SIZE] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    float r[SIZE] = {0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18};

    cout << setw(12) << "P\\n";
    for (int i = 1; i <= n; i++)
        cout << setw(10) << "n=" << i;
    cout << "\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(10) << "P=" << p[i];
        pf = p[i];

        for (int j = 1; j <= n; j++)
        {
            v = pf * (1 + r[i]);
            cout << setw(10) << fixed << setprecision(2) << v;
            pf = v;
        }
        cout << "\n";
    }

    return 0;
}
