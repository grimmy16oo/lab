#include <bits/stdc++.h>
using namespace std;

const int Size = 3;

class Vector
{
    int v[Size];

public:
    Vector() // Default constructor: initializes all elements to 0
    {
        for (int i = 0; i < Size; i++)
        {
            v[i] = 0;
        }
    }
    Vector(int *x) // Parameterized constructor: initializes elements with the given array
    {
        for (int i = 0; i < Size; i++)
        {
            v[i] = x[i];
        }
    }
    friend Vector operator*(int a, Vector b); // Friend function to overload * operator for int * Vector
    friend Vector operator*(Vector a, int b);
    friend ostream &operator<<(ostream &dout, Vector &c); // to overload << operator for vector
};
Vector operator*(int a, Vector b)
{
    Vector c;
    for (int i = 0; i < Size; i++)
    {
        c.v[i] = b.v[i] * a;
    }
    return c;
}
Vector operator*(Vector a, int b)
{
    Vector c;
    for (int i = 0; i < Size; i++)
    {
        c.v[i] = a.v[i] * b;
    }
    return c;
}
ostream &operator<<(ostream &dout, Vector &c)
{
    for (int i = 0; i < Size; i++)
    {
        dout << c.v[i] << " ";
    }
    return dout;
}
int x[Size] = {5, 3, 8};

int main()
{
    Vector v1();
    Vector v2(x);

    Vector v3, v4;
    v3 = 3 * v2;
    v4 = v3 * 6;

    cout << v3 << endl; // Output v3 using overloaded << operator

    return 0;
}