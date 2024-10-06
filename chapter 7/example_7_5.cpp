#include <bits/stdc++.h>
using namespace std;

class invent2;

class invent1
{
    int code;
    int items;
    float price;

public:
    invent1(int a, int b, float c)
    {
        code = a;
        items = b;
        price = c;
    }

    int getcode()
    {
        return code;
    }

    int getitems()
    {
        return items;
    }

    float getprice()
    {
        return price;
    }

    void putdata()
    {
        cout << code << endl;
        cout << items << endl;
        cout << price << endl;
    }

    operator float()
    {
        return (items * price);
    }

};

class invent2
{
    int code;
    float value;

public:
    invent2()
    {
        code = 0;
        value = 0;
    }

    invent2(int x, float y)
    {
        code = x;
        value = y;
    }

    void putdata()
    {
        cout << code << endl;
        cout << value << endl;
    }

    // Constructor for conversion from invent1
    invent2(invent1 p)
    {
        code = p.getcode();
        value = p.getitems() * p.getprice();
    }
};

int main()
{
    invent1 s1(10, 5, 14.2);
    invent2 s2;
    float totalValue;

    totalValue = 5; // Conversion to float
    s2 = s1;         // Conversion to invent2

    s1.putdata();
    cout << totalValue << endl;
    s2.putdata();

    return 0;
}
