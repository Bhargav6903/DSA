#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Array2D
{
public:
    int rows, columns;
    int **p_array;
    vector<tuple<int, int, int>> v;
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
        return v.size();
    }

    int numCols()
    {
        return 3;
    }

    // To clear Normal matrix by given value
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
    // To clear Sparce matrix by given value
    void Spclear(int value)
    {
        for (int i = 0; i < v.size(); i++)
        {
            get<0>(v[i]) = value;
            get<1>(v[i]) = value;
            get<2>(v[i]) = value;
        }
    }
    // TO get element at given index from SPAECE matrix
    int getitem(int i1, int i2)
    {
        cout << "item at entered index:";
        if (i2 == 0)
            return get<0>(v[i1]);
        else if (i2 == 1)
            return get<1>(v[i1]);
        else
            return get<2>(v[i1]);
    }

    void setitem(int i1, int i2, int value)
    {
        p_array[i1 - 1][i2 - 1] = value;
    }
    // smatrix will creat sparce matrix
    void Smatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int k = 0; k < columns; k++)
            {
                if (p_array[i][k] != 0)
                {
                    v.push_back(make_tuple(i, k, p_array[i][k]));
                }
            }
        }
    }
    // To print sparce matrix
    void PrintSp()
    {
        for (int i = 0; i < v.size(); i++)
            cout << get<0>(v[i]) << " "
                 << get<1>(v[i]) << " "
                 << get<2>(v[i]) << "\n";
    }

    // To print Normal matrix
    void print_it()
    {
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
    Array2D obj1(5, 5);
    obj1.clear(0);
    obj1.setitem(3, 2, 1);
    obj1.setitem(2, 2, 4);
    obj1.setitem(4, 4, 11);
    obj1.setitem(1, 4, 16);
    obj1.setitem(1, 3, 6);
    obj1.setitem(2, 4, 67);
    cout << "Normal matrix A" << endl;
    obj1.print_it();
    cout << endl;
    cout << "Sparce matrix of A" << endl;
    obj1.Smatrix();
    obj1.PrintSp();
    cout << endl;
    cout << obj1.getitem(1, 2);
    cout << endl;
    cout << "Rows of sparce matrix: " << obj1.numRows() << endl;
    cout << "Column of sparce matrix: " << obj1.numCols() << endl;
    cout << endl;
    cout << "Cleared sparce matrix by givan value" << endl;
    obj1.Spclear(4);
    obj1.PrintSp();
    return 0;
}