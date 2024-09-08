//CONSTRUCTING MATRIX OBJECTS
#include <bits/stdc++.h>
using namespace std;
class matrix
{
    int **ptr;
    int row, col;

public:
    matrix(int x, int y)
    {
        row = x;
        col = y;

        ptr = new int *[row]; // ptr = new int*[row]; creates an array of pointers, each representing a row
        for (int i = 0; i < row; i++)
        {
            ptr[i] = new int[col]; // ptr[i] = new int[col]; creates a new array of columns for each row.
        }
    }

    void getElement(int i, int j, int val)
    {
        ptr[i][j] = val;
    }
    int &putElement(int i, int j)
    {
        return ptr[i][j];
    }
};

int main()
{
    int m, n, val;
    cout << "enter size of matrix : ";
    cin >> m >> n;

    matrix A(m, n);

    cout << "enter matrix element row by row" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            A.getElement(i, j, val);
        }
    }
    cout << endl;
    cout << A.putElement(1, 2);

    return 0;
}