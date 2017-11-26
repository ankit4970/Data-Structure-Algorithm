//
// Created by ankit on 10/4/2017.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[0].size() ; j++)
            {
                cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};

void printMatrix(vector<vector<int>>& matrix)
{
    for(int i = 0 ; i < matrix.size() ; i++)
    {
        for(int j = 0 ; j < matrix[0].size() ; j++ )
        {
            std::cout << matrix[i][j] << "," ;
        }
        std::cout << endl;
    }
}

void matrixMultiplication( )
{
    vector<vector<int>> matrix1 = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
    };

    vector<vector<int>> matrix2 = {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1}
    };

    vector<vector<int>> res(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));

    for (int i = 0 ; i < matrix1.size() ; ++i)
    {
        for (int j = 0 ; j < matrix2[0].size() ; ++j )
        {
            for (int k = 0 ; k < matrix2.size() ; ++k )
            {
                res[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    printMatrix(res);
}

void matrixRotate90()
{
    vector<vector<int>> matrix = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int M = matrix.size()-1;

    for( int i = 0 ; i < ceil(matrix.size()/2.0) ; i++ )
    {
        for( int j = i ; j < M-i ; j++)
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

void matrixMain()
{
    std::cout << "Hello from matrixMain" << std::endl;

    Solution sol;
    vector<vector<int>> matrix = {
                                    { 1, 2, 3 },
                                    { 4, 5, 6 },
                                    { 7, 8, 9 }
                                };
    //sol.spiralOrder(matrix);
    matrixMultiplication();
    matrixRotate90();
}