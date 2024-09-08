//DYNAMIC INIALIZATION OF CONSTRUCTOR
#include <bits/stdc++.h>
using namespace std;

class fixedDeposit
{
    long int P;
    int years;
    float rate, returnVal;

public:
    fixedDeposit() {}                                // Default constructor
    fixedDeposit(long int p, int y, float r = 0.12); // Constructor with float rate
    fixedDeposit(long int p, int y, int r);          // Constructor with integer rate
    void display();
};

fixedDeposit::fixedDeposit(long int p, int y, float r)
{
    P = p;
    years = y;
    rate = r;

    returnVal = P;
    for (int i = 0; i < years; i++)
    {
        returnVal *= (1.0 + rate);
    }
}

fixedDeposit::fixedDeposit(long int p, int y, int r)
{
    P = p;
    years = y;
    rate = float(r) / 100; // Convert integer rate to float

    returnVal = P;
    for (int i = 0; i < years; i++)
    {
        returnVal *= (1.0 + rate);
    }
}

void fixedDeposit::display()
{
    cout << "Principal value: " << P << endl;
    cout << "Return value: " << returnVal << endl;
}

int main()
{
    fixedDeposit f1, f2, f3;
    long int p;
    int y, R;
    float r;

    cout << "Enter principal, years, and rate as float(%): " << endl;
    cin >> p >> y >> R;
    f1 = fixedDeposit(p, y, R); 

    cout << "Enter principal, years, and rate as int: " << endl;
    cin >> p >> y >> r;
    f2 = fixedDeposit(p, y, r); 

    cout << "Enter principal and years: " << endl;
    cin >> p >> y;
    f3 = fixedDeposit(p, y);        //will call constructor with default parameter for (r)

    cout << "\nDeposit 1" << endl;
    f1.display();

    cout << "\nDeposit 2" << endl;
    f2.display();

    cout << "\nDeposit 3" << endl;
    f3.display();

    return 0;
}
