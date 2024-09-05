#include <bits/stdc++.h>
using namespace std;

class ClassB; // Forward declaration

class ClassA
{
    int a;

public:
    void setValue(int x)
    {
        a = x;
    }
    friend void findMax(ClassA, ClassB);
};

class ClassB
{
    int b;

public:
    void setValue(int y)
    {
        b = y;
    }
    friend void findMax(ClassA, ClassB);
};

void findMax(ClassA A, ClassB B)    //has access to their private members a and b as its a friend function
{
    if (A.a >= B.b)
        cout << "Maximum value: " << A.a << endl;
    else
        cout << "Maximum value: " << B.b << endl;
}

int main()
{
    ClassA A;
    A.setValue(10);

    ClassB B;
    B.setValue(20);

    findMax(A, B);

    return 0;
}
