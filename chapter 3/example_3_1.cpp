#include <iostream>
using namespace std;
int m = 10;
int main()
{
    int m = 20;
    {
        int k = m;
        int m = 30;

        cout << "we are in inner Block" << endl;
        cout << "k =" << k << endl;
        cout << "m =" << m << endl;
        cout << "::m = " << ::m << endl;
    }
    cout << "\n we are in outer block" << endl;
    cout << "m = " << m << endl;
    cout << "::m = " << ::m << endl;
    return 0;
}