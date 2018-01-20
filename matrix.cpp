//
// Created by ankit on 10/4/2017.
//
#include "common.h"
#include <vector>
#include <cmath>


void Matrix::printMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
}

void Matrix::matrixMultiplication() {
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    vector<vector<int>> matrix2 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

    vector<vector<int>> res(matrix1.size(), vector<int>(matrix2[0].size(), 0));

    for (int i = 0 ; i < matrix1.size() ; ++i)
    {
        for (int j = 0 ; j < matrix2[0].size() ; ++j)
        {
            for (int k = 0 ; k < matrix2.size() ; ++k)
            {
                res[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    printMatrix(res);
}

void Matrix::matrixRotate90()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int M = matrix.size() - 1;

    for (int i = 0; i < matrix.size() / 2.0; i++)
    {
        for (int j = i; j < M-i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[M-j][i];
            matrix[M-j][i] = matrix[M-i][M-j];
            matrix[M-i][M-j] = matrix[j][M-i];
            matrix[j][M-i] = temp;
        }
    }
    printMatrix(matrix);
}

// m1,m2 * n1,n2
void Matrix::multiply(int m1, int m2, int **mat1, int n1, int n2, int **mat2)
{
    int x, i, j;
    int res[m1][n2];
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            res[i][j] = 0;
            for (x = 0; x < m2; x++)
            {
                res[i][j] += mat1[i][x] * mat2[x][j];
            }
        }
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d ", *(*(res + i) + j));
        }
        printf("\n");
    }
}

void Matrix::matrixMain()
{
    cout << "Hello from matrixMain" << endl;


    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    matrixMultiplication();
    matrixRotate90();
}

