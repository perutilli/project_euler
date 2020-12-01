#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 15;

void maxSum(int[][SIZE], int, int, int *, int *);

int main()
{

    ifstream triangle_f;
    triangle_f.open("prob18//triangle.txt");
    int n, row_n = 0, col_n = 0;
    int sum, max;

    int mat[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            mat[i][j] = -1;
        }
    }

    bool open = triangle_f.is_open();

    while (triangle_f >> n)
    {
        if (col_n > row_n)
        {
            row_n++;
            col_n = 0;
        }

        mat[row_n][col_n] = n;

        col_n++;
    }

    triangle_f.close();

    max = 0;
    sum = mat[0][0];
    maxSum(mat, 0, 0, &sum, &max);

    cout << max;

    return 0;
}

void maxSum(int mat[][SIZE], int row, int col, int *sum, int *max)
{

    if (row >= SIZE - 1)
    {
        if (*sum > *max)
        {
            *max = *sum;
        }
        return;
    }

    *sum += mat[row + 1][col];
    maxSum(mat, row + 1, col, sum, max);
    *sum -= mat[row + 1][col];
    if (col + 1 <= row + 1)
    {
        *sum += mat[row + 1][col + 1];
        maxSum(mat, row + 1, col + 1, sum, max);
        *sum -= mat[row + 1][col + 1];
    }

    return;
}