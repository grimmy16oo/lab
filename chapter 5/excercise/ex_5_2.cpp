#include <iostream>
using namespace std;

class MyVector
{
    float *p;
    int size;

public:
    MyVector() : p(nullptr), size(0) {} // Constructor to initialize size and pointer
    ~MyVector() { delete[] p; }         // Destructor to free allocated memory
    void create_vector(int a);
    void set_element(int i, float value);
    void multiply(float b);
    void display(void) const;
    void modify_element();
    void delete_element();
};

void MyVector::create_vector(int a)
{
    size = a;
    p = new float[size];
}

void MyVector::set_element(int i, float value)
{
    if (i >= 0 && i < size)
    {
        p[i] = value;
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

void MyVector::multiply(float b)
{
    for (int i = 0; i < size; i++)
    {
        p[i] = b * p[i];
    }
}

void MyVector::display(void) const
{
    cout << "Vector: ( ";
    for (int i = 0; i < size; i++)
    {
        cout << p[i];
        if (i < size - 1)
        {
            cout << " , ";
        }
    }
    cout << " )" << endl;
}

void MyVector::modify_element()
{
    int i;
    cout << "Enter the position of the element to modify (1-based index): ";
    cin >> i;
    if (i >= 1 && i <= size)
    {
        cout << "Enter new value for element " << i << ": ";
        float v;
        cin >> v;
        set_element(i - 1, v);
        cout << "Modified vector: ";
        display();
    }
    else
    {
        cout << "Invalid position!" << endl;
    }
}

void MyVector::delete_element()
{
    int i;
    cout << "Enter the position of the element to delete (1-based index): ";
    cin >> i;
    if (i >= 1 && i <= size)
    {
        for (int j = i - 1; j < size - 1; j++)
        {
            p[j] = p[j + 1]; // Shift elements to the left
        }
        size--; // Reduce size of the vector
        cout << "After deletion, vector: ";
        display();
    }
    else
    {
        cout << "Invalid position!" << endl;
    }
}

int main()
{
    MyVector santo;
    int s;
    cout << "Enter the size of the vector: ";
    cin >> s;

    santo.create_vector(s);

    cout << "Enter " << s << " elements one by one: " << endl;
    for (int i = 0; i < s; i++)
    {
        float v;
        cin >> v;
        santo.set_element(i, v);
    }

    cout << "Initial vector: ";
    santo.display();

    cout << "Enter a scalar value to multiply the vector: ";
    float m;
    cin >> m;
    santo.multiply(m);

    cout << "After multiplication: ";
    santo.display();

    // Modify and delete operations
    santo.modify_element();
    santo.delete_element();

    return 0;
}
