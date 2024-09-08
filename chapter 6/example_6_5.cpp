//CONSTRUCTOR WITH NEW
#include <bits/stdc++.h>
using namespace std;

class str {
    char *name;  // pointer to char array
    int len;
public:
    str()  
    {
        len = 0;
        name = new char[len + 1];
        name[0] = '\0';  // initialize with an empty string
    }
    
    str(const char *s)  // Parameterized constructor
    {
        len = strlen(s);
        name = new char[len + 1];
        strcpy(name, s);       //Copies the content of s to name 
    }

    ~str()  // destructor to release allocated memory
    {
        delete[] name;
    }

    void display()
    {
        cout << name << endl;
    }

    void join(const str &a, const str &b);
};

void str::join(const str &a, const str &b)
{
    len = a.len +  b.len;
    delete[] name;

    name = new char[len + 1];

    strcpy(name, a.name);           //Copies the string from a to name
    strcat(name, b.name);        //Appends the string from b to name.
}

int main()
{
    const char *first = "joe ";
    str n1(first), n2("max "), n3("chloe"), s1, s2;

    s1.join(n1, n2);
    s2.join(s1, n3);

    n1.display();
    n2.display();
    n3.display();
    s1.display();
    s2.display();

    return 0;
}
