#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Gameoflife
{
public:
    int rows, columns;
    int **p_array;
    Gameoflife(int nrows, int ncols)
    {
        this->rows = nrows;
        this->columns = ncols;
        p_array = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            p_array[i] = new int[columns];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                p_array[i][j] = 0;
            }
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

    void clearcell(int x, int y)
    {
        p_array[x][y] = 0;
    }

    void setcell(int x, int y)
    {
        p_array[x][y] = 1;
    }

    bool islive(int x, int y)
    {
        return p_array[x][y];
    }

    void configure(vector<pair<int, int>> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            p_array[v[i].first][v[i].second] = 1;
        }
    }

    int numLiveNeighbors(int x, int y)
    {
        cout << "Number of live neighbours for " << x << "," << y << " index" << endl;
        int sum = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (x + i < 0 || y + j < 0 || x + i > rows - 1 || y + j > columns - 1)
                    continue;
                sum += p_array[x + i][y + j];
            }
        }
        sum -= p_array[x][y];
        return sum;
    }

    void print_it()
    {
        cout << "Following is the matrix: -\n";
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
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 3}};
    Gameoflife g1(4, 4);
    g1.setcell(1, 1);
    g1.setcell(2, 2);
    g1.setcell(0, 1);
    // cout << g1.islive(1, 1) << endl;
    g1.configure(v);
    g1.print_it();
    cout << g1.numLiveNeighbors(2, 3);
    return 0;
}