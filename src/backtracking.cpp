/* **************************************************************************************
*   @file     		    backtracking.cpp
*   @brief              This source file contains backtracking problems in C/C++.
*   @version            Revision: 1.00
*   @date               01/01/18
*   @author             ankit
****************************************************************************************/


#include "backtracking.h"


void BackTrackingClass::coinChangeCombinations(int amount, vector<int>& coins)
{
    vector<int> table(amount+1,0);
    table[0]=1;
    for (int val : coins)    //1,2,5
    {
        for (int i=val ; i<=amount ; i++) // 1,2,3,4,5
        {
            table[i] += table[i - val];
            cout << table[i] << ",";
        }
        cout << endl;
    }
}

void BackTrackingClass::coinChange(int amount, vector<int>& coins)
{
    vector<int> table(amount+1,amount+1);
    table[0] = 0;
    for (int i = 1 ; i <= amount ; i++)
    {
        for (int j = 0 ; j < coins.size() && coins[j] <= i ; j++ )
        {
            table[i] = min(table[i], table[i-coins[j]]+1);
        }
    }
    cout << table[amount] << endl;
}

void BackTrackingClass::subsetsUtil(vector<int>& nums, vector<vector<int>>& combs,
                                    int index, vector<int>& combinations)
{
    if(!combinations.empty())
    {
        combs.push_back(combinations);
    }
    for(int i = index ; i < nums.size() ; ++i)
    {
        combinations.push_back(nums[i]);
        subsetsUtil(nums, combs, i+1, combinations);
        combinations.pop_back();
    }
}
vector<vector<int>> BackTrackingClass::subsets(vector<int>& nums)
{
    vector<vector<int>> combs;
    vector<int> combinations;
    subsetsUtil(nums, combs, 0, combinations);
    return combs;
}

/* **************************************************************************************
 *  Given a collection of integers that might contain duplicates, nums, return all
 *  possible subsets (the power set).
 *  Note: The solution set must not contain duplicate subsets.
 *   For example, If nums = [1,2,2], a solution is:
 *              [
 *                  [2],
 *                  [1],
 *                  [1,2,2],
 *                  [2,2],
 *                  [1,2],
 *                  []
 *              ]
 ***************************************************************************************/
void BackTrackingClass::subsetsDupUtil(vector<int>& nums, vector<vector<int>>& combs,
                                       int index, vector<int>& combinations)
{
    combs.push_back(combinations);                          // adding [], empty set as well
    for(int i = index ; i < nums.size() ; ++i)
    {
        if (i == index || nums[i] != nums[i-1])
        {
            combinations.push_back(nums[i]);
            subsetsDupUtil(nums, combs, i+1, combinations);
            combinations.pop_back();
        }
    }
}

vector<vector<int>> BackTrackingClass::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> combs;
    vector<int> combinations;
    sort(nums.begin(),nums.end());
    subsetsDupUtil(nums, combs, 0, combinations);
    return combs;
}

void BackTrackingClass::backTrackMain()
{
    vector<int> nums1 = {1,2,5};
    vector<vector<int>> combi  = subsets(nums1);
    vector<int> nums2 = {1,2,2};
    subsetsWithDup(nums2);
}