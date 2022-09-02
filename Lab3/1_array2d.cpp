#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Array2D
{
public:
    int rows, columns;
    int **p_array;
    Array2D(int nrows, int ncols)
    {
        this->rows = nrows;
        this->columns = ncols;
        p_array = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            p_array[i] = new int[columns];
        }
    }

    int numRows()
    {
        return this->rows;
    }

    int numCols()
    {
        return this->columns;
    }

    void clear(int value)
    {

        for (int i = 0; i < rows; i++)
        {
            for (int k = 0; k < columns; k++)
            {
                p_array[i][k] = value;
            }
        }
    }

    int getitem(int i1, int i2)
    {
        return p_array[i1 - 1][i2 - 1];
    }

    void setitem(int i1, int i2, int value)
    {

        p_array[i1 - 1][i2 - 1] = value;
    }

    void print_it()
    {
        cout << "Following is the matrix: -\n";
        // cout<<"\nStarted on print_val\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << p_array[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D obj1(4, 4);
    cout << "\nRows = " << obj1.numRows() << "\n";
    cout << "\nColumns = " << obj1.numCols() << "\n\n";
    obj1.clear(5);
    obj1.setitem(3, 2, 1);
    obj1.setitem(2, 2, 4);
    obj1.setitem(4, 4, 10);
    obj1.print_it();
    cout << obj1.getitem(6, 3) << endl;
    cout << obj1.getitem(3, 2) << endl;
    return 0;
}