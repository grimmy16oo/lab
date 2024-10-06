//OVERLOADING BINARY OPERATORS
#include<bits/stdc++.h>
using namespace std;
class Complex{
    float x;
    float y;

    public:
        Complex(){};
        Complex(float real,float imag)
        {
            x = real;
            y = imag;
        }
        void display()
        {
            cout<<x<<" + "<<y<<"i"<<endl;
        }
        Complex operator+(Complex c2);
};
Complex Complex :: operator+(Complex c2)
{
    Complex temp;

    temp.x = x + c2.x;
    temp.y = y + c2.y;

    return temp;
}
int main()
{
    Complex c1(1.5,3.8);
    Complex c2(4.2,6.7);
    Complex c3 = c1+c2;     //c1.operator+(c2)

    c3.display();
    
    return 0;
}