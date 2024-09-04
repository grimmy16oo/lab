#include <iostream>
using namespace std;
class person
{
    char name[30];
    int age;

public:
    void getdata();
    void display();
};
void person::getdata()
{
    cout << "Name : ";
    cin >> name;
    cout << "Age : ";
    cin >> age;
}

void person::display()
{
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
}

int main()
{
    person p;
    p.getdata();
    p.display();

    return 0;
}
