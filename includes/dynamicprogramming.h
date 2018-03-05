//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_DYNAMICPROGRAMMING_H
#define INTERVIEW_DYNAMICPROGRAMMING_H


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class dynamicProgramClass
{
    int longestCommonSubsequence(char* source, char*target);
    int longestCommonSubstring(char* source, char*target);

    int longestPalindromicSubsequence(char* str);
    int longestPalindromicSubstring(char* str);
    int uniquePaths(int m, int n);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    int coinChange(vector<int>& coins, int amount);
    int coinChange2(vector<int>& coins, int amount);
    int longestIncreasingSubArray(vector<int>& nums);

public:
    void dpMain();
};

#endif //INTERVIEW_DYNAMICPROGRAMMING_H
