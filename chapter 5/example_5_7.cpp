#include <bits/stdc++.h>
using namespace std;
class sample
{
    int a;
    int b;

public:
    void setval()
    {
        a = 25;
        b = 40;
    }
    friend float mean(sample s);    //use of friend function to calculate the mean of two private member variables in a class
};
float mean(sample s)
{
    return float(s.a + s.b) / 2.0;
}
int main()
{
    sample x;
    x.setval();

    cout << "mean value = " << mean(x) << endl;

    return 0;
}