/* **************************************************************************************
*   @file     		    sort.cpp
*   @brief              This source file contains dynamic programming problems in C/C++.
*   @version            Revision: 1.00
*   @date               01/03/18
*   @author             ankit
****************************************************************************************/

#include <climits>
#include "dynamicprogramming.h"

int dynamicProgramClass::longestCommonSubsequence(char* source, char*target)
{

}

int dynamicProgramClass::longestCommonSubstring(char* source, char*target)
{

}

int dynamicProgramClass::longestPalindromicSubsequence(char* str)
{
    int length = strlen(str);
    int L[length][length];

    for(int i = 0 ; i < length ; i++)
    {
        L[i][i] = 1;
    }

}

int dynamicProgramClass::longestPalindromicSubstring(char* str)
{

}
// Return minimum number of coins required to make amount
int dynamicProgramClass::coinChange(vector<int>& coins, int amount)
{
    int max = amount+1;
    vector<int> table(amount+1,max);
    table[0] = 0;

    for (int i = 1 ; i <= amount ; i++)
    {
        for (int j = 0 ; j < coins.size() ; j++)
        {
            if (coins[j] <= i)
            {
                table[i] = min(table[i] , table[i-coins[j]]+1);
            }
        }
    }

    return table[amount];
}

// Return number of combinations that make up that amount.
int dynamicProgramClass::coinChange2(vector<int>& coins, int amount)
{
    vector<int> table(amount+1, 0);
    table[0] = 1;

    for (int i = 0 ; i < coins.size() ; ++i)
    {
        for (int j = 1 ; j <= amount ; ++j)
        {
            if (coins[i] <= j)
            {
                table[j] += table[j-coins[i]];
            }
        }
    }

    return table[amount] ;
}

int dynamicProgramClass::uniquePaths(int m, int n)
{
    vector<vector<int>> table(m, vector<int>(n,0));
    table[0][0] = 1;
    for (int i = 0 ; i < m ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 1;
            }
            else
            {
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
    }

    return table[m-1][n-1];
}

int dynamicProgramClass::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int row = obstacleGrid.size();
    int colomn = obstacleGrid[0].size();

    vector<vector<int>> table(row,vector<int>(colomn,0));
    table[0][0] = 1;

    for (int i = 0 ; i < row ; ++i)
    {
        for (int j = 0 ; j < colomn ; ++j)
        {
            if (i == 0)
            {
                table[i][j] = (obstacleGrid[i][j])?0:(table[i][(j>0)?(j-1):0]);
            }
            else if ( j == 0)
            {
                table[i][j] = (obstacleGrid[i][j])?0:(table[(i>0)?(i-1):0][j]);
            }
            else
            {
                if (obstacleGrid[i][j] == 0)
                {
                    table[i][j] = table[i-1][j] + table[i][j-1];
                }
                else if (obstacleGrid[i][j] == 1)
                {
                    table[i][j] = 0;
                }

            }
        }
    }

    return table[row-1][colomn-1];
}

int dynamicProgramClass::longestIncreasingSubArray(vector<int>& nums)
{
    vector<int> table(nums.size(),1);

    for (int i = 0 ; i < nums.size() ; i++)
    {
        for (int j = 0 ; j < i ; j++)
        {
            if (nums[i] > nums[j] && (table[i] < table[j] + 1))
            {
                table[i] = table[j] + 1;
            }
        }
    }

    int max = INT_MIN;
    for(int i = 0 ; i < table.size() ; i++)
    {
        cout << table[i] << endl;
        if(max < table[i])
        {
            max = table[i];
        }
    }

    return max;
}


void dynamicProgramClass::dpMain()
{

}