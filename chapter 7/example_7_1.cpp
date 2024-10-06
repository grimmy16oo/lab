//OVERLOADING UNARY MINUS
#include<bits/stdc++.h>
using namespace std;
class space{
    int x;
    int y;
    int z;

    public:
        void getdata(int a,int b,int c)
        {
            x = a;
            y = b;
            z = c;
        }
        void display()
        {
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        void operator-();
};
void space :: operator-()
{
    x = -x;
    y = -y;
    z = -z;
}
int main()
{
    space s;
    
    s.getdata(4,9,6);
    s.display();

    -s;
    s.display();
    
    return 0;
}