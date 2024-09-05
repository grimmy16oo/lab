#include <bits/stdc++.h>
using namespace std;
class item
{
    static int count;       //Only one copy of count exists, regardless of how many item objects are created
    int num;                //num is a regular instance variable, meaning each item object has its own copy of num.

public:
    void getdata(int a)
    {
        num = a;
        count++;
    }
    void getcount()
    {
        cout << "count : " << count << endl;
    }
};
int item ::count;       //defination of static data member. the static variable must be defined outside the class (but only once)
int main()
{
    item a, b;

    a.getcount();       //prints count's initialized value 0
    b.getcount();       //prints count's initialized value 0

    a.getdata(100);
    b.getdata(200);

    cout << "After reading data" << endl;
    a.getcount();
    b.getcount();

    return 0;
}