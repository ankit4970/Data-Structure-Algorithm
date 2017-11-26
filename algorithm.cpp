/*
 * algorithm.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: ankit
 */

#include<iostream>
#include<climits>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <set>
//#include <bits/unordered_map.h>

using namespace std;

// Dimentions of paint screen
#define     M   4
#define     N   4

/* Utility Macros to get max and min of 2 numbers */
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

// Linklist node structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*******************************************************************************
 * addTwoNumbers -  add two numbers given as digits in linkedlist
 ******************************************************************************/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}

/******************************************************************************
 * maxSubArraySum -  find the subarray with maximum sum
 *****************************************************************************/
int maxSubArraySum()
{
    vector<int> nums {1,4,5,-11,9,1,2,4,7,6};

    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0, s = 0;

    for (int i = 0 ; i < nums.size() ; i++)
    {
        max_ending_here += nums[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i+1;
        }
    }

    cout << "start index : " << start <<endl;
    cout << "end index : " << end <<endl;
    return max_so_far;
}

bool isSubsequenceNew(char* s, char* t) {

    while (*t)
        s = s + (*s == *t++);
    return !*s;
}

bool isSubsequence(char* s, char* t) {

    if(strlen(s) == 0)
    {
        return true;
    }
    if(strlen(t) == 0)
    {
        return false;
    }

    if(s[0] == t[0])
    {
        return isSubsequence(&s[1],&t[1]);
    }
    else
    {
        return isSubsequence(&s[0], &t[1]);
    }
}

//{2,4,3,2,1,6,3,1} // Not working
void subArraySum(vector<int>& nums, int reqSum, int& start, int& end)
{
    int res = nums[0], sum = 0;
    start = 0;
    end = 0;
    int near = INT_MAX;
    int temp =0;
    if(res == reqSum)
    {
        return;
    }

    for (int i = 0 ; i < nums.size() ; i++)
    {
        sum += nums[i];
        if(sum < reqSum)
        {
            near = sum;
            end = i ;
        }
        else if (sum > reqSum)
        {
            sum = sum - nums[start];
            start++;
        }
    }
}

/****************************************************************************************
 * Given two sequences, find the length of longest subsequence present in both of
 * them. A subsequence is a sequence that appears in the same relative order,
 * but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”,
 * ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has
 * 2^n different possible subsequences.Returns length of LCS for X[0..m-1], Y[0..n-1]
****************************************************************************************/
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/******************************************************************************
 * lcs_dp -  longest common subsequence
 *****************************************************************************/
int lcs_dp( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0 ; i <= m ; i++)
    {
        for (j = 0 ; j <=n ; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);

            cout << L[i][j] << ",";
        }

        cout << endl;
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}



void noOfWays(int m, int n)
{
    int matrix[m][n] = {};

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++ )
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else
                matrix[i][j] = matrix[i][j-1] + matrix[i-1][j] + matrix[i-1][j-1];
        }
    }

    cout << "Total ways are " << matrix[m-1][n-1];
}


// A recursive function to replace previous color 'prevC' at  '(x, y)'
// and all surrounding pixels of (x, y) with new color 'newC' and
void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newC;

    // Recur for north, east, south and west
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}



/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> temp;
    std::map<int, int> map;
    std::map<int,int>::iterator it;
    map.insert(std::pair<int,int>(nums[0], 0));

    for (int i = 1; i < nums.size(); i++)
    {
        int comp = target - nums[i];
        it = map.find(comp);

        if (it != map.end() && it->second != i)
        {
            temp.push_back(it->second);
            temp.push_back(i);
            break;
        }
        else
        {
            map.insert(std::pair<int,int>(nums[i], i));
        }
    }
    return temp;
}

// Maximum Distance in Array
// Given m arrays, and each array is sorted in ascending order.
// Now you can pick up two integers from two different arrays
// (each array picks one) and calculate the distance.
// We define the distance between two integers a and b to be their
// absolute difference |a-b|. Your task is to find the maximum distance.
int maxDistanceArray()
{
    std::vector<std::vector<int>> list = {{1,2,3},{4,5},{1,2,3}};

    int res = 0;
    int min_val = list[0][0];
    int max_val = list[0][list[0].size() - 1];

    for (int i = 1; i < list.size(); i++)
    {
        res = max(res, max(abs(list[i][list[i].size() - 1] - min_val), abs(max_val - list[i][0])));
        min_val = min(min_val, list[i][0]);
        max_val = max(max_val, list[i][list[i].size() - 1]);
    }
    std::cout << res << std::endl ;
}

int longestIncreasingSubArray(vector<int>& nums)
{
    vector<int> table(nums.size(),1);

    for(int i = 0 ; i < nums.size() ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(nums[i] > nums[j] && (table[i] < table[j] + 1))
            {
                table[i] = table[j] + 1;
            }
        }
    }

    int max = INT_MIN;
    for(int i = 0 ; i < table.size() ; i++)
    {
        std:cout << table[i] << std::endl;
        if(max < table[i])
        {
            max = table[i];
        }
    }

    return max;
}



// Return minimum number of coins required to make amount
int coinChange(vector<int>& coins, int amount) {
    int max = amount+1;
    vector<int> table(amount+1,max);
    table[0] = 0;

    for(int i = 1 ; i <= amount ; i++)
    {
        for(int j = 0 ; j < coins.size() ; j++)
        {
            if(coins[j] <= i)
            {
                table[i] = min(table[i] , table[i-coins[j]] + 1);
            }
        }
    }

    return table[amount];
}



void printSolutionMaze(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y) == true)
    {
        sol[x][y] = 1;

        if ((solveMazeUtil(maze, x+1, y, sol) == true) || (solveMazeUtil(maze, x, y+1, sol) == true))
        {
            return true;
        }
        else
        {
            sol[x][y] = 0;
            return false;
        }

    }
    return false;
}

void moveZeroes(vector<int>& nums)
{
    unsigned int index = 0 ;

    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[index], nums[i]);
            index++;
        }
    }
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}
    };

    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist\n");
        return false;
    }

    printSolutionMaze(sol);
    return true;

}

// Stock buy and sell (Single transactions allowed)
void maxProfit()
{
    vector<int> prices = {7, 1, 5, 8, 6, 9};
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    cout << maxPro << endl;
}

// Stock buy and sell (Multiple transactions allowed)
void maxProfitMulti()
{
    vector<int> prices = {7, 1, 3, 8, 6, 9};
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p)
    {
        ret += max(prices[p] - prices[p - 1], 0);
    }
    cout << ret << endl;
}


void maxProfitTwo()
{
    vector<int> prices = {7, 1, 3, 8, 6, 9};
    int maxPro = 0;
    int minPrice = INT_MAX;
    vector<int> table(prices.size(),-1);
    table[0] = 0;
    int first = 0;
    int second = 0;
    for (size_t p = 0; p < prices.size(); ++p)
    {
        minPrice = min(minPrice, prices[p]);
        table[p] = max(maxPro, prices[p] - minPrice);
    }

    for (size_t p = 0; p < prices.size(); ++p)
    {
        cout << table[p] << "," ;
    }
    cout << endl;
    for (int i = 0; i < prices.size(); i++)
    {
        if(first < table[i])
        {
            first = table[i];
            second = first;
        }
    }
    cout << endl;
}
void subSequence()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int test;
    std::cin >> test;
    while(test --)
    {
        unsigned int n,k,x;
        std::cin >> n >> k;
        unsigned int sum[n];
        sum[0] = 0;
        int cnt[k]={};
        cnt[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            std::cin >> x;
            sum[i] = (sum[i-1] + x)%k;
            cnt[ sum[i] ] ++;
        }

        long long res = 0;
        for(int r = 0; r < k; r ++)
            res += (cnt[r]*(cnt[r]-1)/2);

        std::cout<< res << std::endl;
    }
}

void setZerosUtil(vector<vector<int>>& matrix, int i, int j) {

    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
    {
        return;
    }

    if(matrix[i][i] != 0)
        matrix[i][j] = 'x';

}

void setZeroes(vector<vector<int>>& matrix,set<int>& row,set<int>& colomn)
{

    for(int i = 0 ; i < matrix.size() ; i++)
    {
        for(int  j = 0 ; j < matrix[0].size() ; j++)
        {
            if(matrix[i][j] == 0)
            {
                cout << "Row : " << i << "Column : " << j << endl;
                row.insert(i);
                colomn.insert(j);
            }
        }
    }



}

// Driver program to test above function
void algoMain()
{
    std::cout << "Hello from algoMain" << std::endl;

    //isSubsequence();
    //cout << maxSubArraySum() << endl;
#if 0
#if 0
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC);

    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }

#endif
    vector<int> nums = {2,4,3,2,1,6,3,1};

    for(auto it = nums.begin() ; it != nums.end() ; it++)
    {
        std::cout << it.operator*();
    }
    cout << endl;
    int start,end;
    //int max_sum = maxSubArraySum(nums);
    subArraySum(nums,8,start,end);
    //cout << "Maximum contiguous sum is " << max_sum;

    //noOfWays(2,2);
    //cout << endl;
    // LCS
    //char X[] = "AGGTABY";
    //char Y[] = "GXTXAYBZ";

    //int m = strlen(X);
    //int n = strlen(Y);

    //printf("Length of LCS is %d", lcs_dp( X, Y, m, n ) );
	//return 0;
    vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
    std::cout << longestIncreasingSubArray(nums) << std::endl;
#endif
    int maze[N][N]  =  { {1, 0, 1, 1},
                         {1, 1, 0, 1},
                         {0, 1, 0, 1},
                         {1, 1, 1, 1}
    };

    vector<vector<int>> matrix = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    //solveMaze(maze);
    //maxProfit();
    //maxProfitMulti();
    //maxProfitTwo();
    set<int> row;
    set<int> colomn;
    for(int i = 0 ; i < matrix.size() ; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    setZeroes(matrix, row, colomn);

    for (auto it = row.begin(); it!=row.end(); ++it)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[*it][i] = 0;
        }
    }
    for (auto it = colomn.begin(); it!=colomn.end(); ++it)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][*it] = 0;
        }
    }
    for(int i = 0 ; i < matrix.size() ; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
}

