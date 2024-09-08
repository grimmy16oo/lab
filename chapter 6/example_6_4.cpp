//COPY CONSTRUCTOR
#include<bits/stdc++.h>
using namespace std;

class code
{
    int ID;

public:
    code(){}
    code(int x)
    {
        ID = x;
    }
    code(code &copy)        //copy constructor initializes a with the value of a from another object (copy).
    {
        ID = copy.ID;
    }

    void display()
    {
        cout<<ID<<endl;
    }
};

int main()
{
    code c1(100);       //parameterized constructor is called
    code c2(c1);        //copy constructor is called
    code c3 = c1;       //copy constructor is called
    code c4;            //default constructor is called
    c4 = c1;

    cout<<"id of c1 : ";
    c1.display();
    cout<<"id of c2 : ";
    c2.display();
    cout<<"id of c3 : ";
    c3.display();
    cout<<"id of c4 : ";
    c4.display();

    return 0;
}