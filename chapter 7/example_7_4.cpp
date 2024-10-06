#include <bits/stdc++.h>
using namespace std;
class String
{
    int len;
    char *str;

public:
    String() // default constructor
    {
        len = 0;
        str = 0;
    }
    String(const char *s) // create string from arrays
    {
        len = strlen(s);
        str = new char[len + 1]; // Allocates memory for str

        strcpy(str, s); // copies the contents of s into str
    }
    String(const String &s) // copy constructor. syntax : ClassName(const ClassName &source);
    {
        len = s.len;
        str = new char[len + 1];

        strcpy(str, s.str);
    }
    ~String() // destructor (bcz we used new)
    {
        delete[] str;
    }

    String &operator=(const String &s) // The return type is a reference to the current object (*this)
    {
        if (this != &s) // The check (this != &s) ensures that the assignment operator does nothing if an object is assigned to itself. Without this check, the assignment would proceed to delete its own data, leading to undefined behavior.
        {
            delete[] str;            // Free existing memory
            len = s.len;             // The length of the current object is updated to match the source object.
            str = new char[len + 1]; // New memory is allocated for the current object's string, large enough to hold the source string and a null terminator.
            strcpy(str, s.str);
        }
        return *this;
    }

    friend String operator+(const String &s, const String &t); // Passing objects by reference avoids copying the object. Adding const ensures the compiler that the object will not be modified
    friend int operator<=(const String &s, const String &t);

    friend void display(const String &s);
};

String operator+(const String &s, const String &t)
{
    String temp;

    temp.len = s.len + t.len;
    temp.str = new char[temp.len + 1];

    strcpy(temp.str, s.str);
    strcat(temp.str, t.str);

    return temp;
}
int operator<=(const String &s, const String &t)
{
    int m = strlen(s.str);
    int n = strlen(t.str);

    if (m <= n)
        return 1;
    else
        return 0;
}
void display(const String &s)
{
    cout << s.str << endl;
}

int main()
{
    String s1 = "New";
    String s2 = "York";
    String t1, t2, t3;
    t1 = s1;
    t2 = s2;
    t3 = s1 + s2; // The issue with t3 not displaying as expected is likely due to the assignment operator not being overloaded.

    display(t1);
    display(t2);
    display(t3);

    return 0;
}