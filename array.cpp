//
// Created by ankit on 11/11/2017.
//
#include "common.h"
#include <vector>
#include <map>

// Find the maximum value subarray
int maxSumSubArray()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int sum = nums[0], res = nums[0];

    for(int num : nums)
    {
        sum = max(num, sum+num);
        res = max(sum, res);
    }
    return res;
}
// Find the subarray whose sum is equal to the given sum
int subarraySum()
{
    vector<int> arr = {1, 2, 3, 7, 9};
    int target = 5;
    int sum = arr[0];
    int start = 0, end = 0;
    bool flag = false;

    while((start < arr.size()) && (end < arr.size()))
    {
        if(sum > target)
        {
            sum -= arr[start];
            start++;
        }
        else if(sum < target)
        {
            end++;
            sum += arr[end];
        }
        if(sum == target)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        cout << "Start is : " << start << endl;
        cout << "End is : " << end << endl;
    }
    else
    {
        cout << "Couldn't found "<< endl;
    }

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
    map<int, int> Map;
    map<int,int>::iterator it;
    Map.insert(pair<int,int>(nums[0], 0));

    for (int i = 1; i < nums.size(); i++)
    {
        int comp = target - nums[i];
        it = Map.find(comp);

        if (it != Map.end() && it->second != i)
        {
            temp.push_back(it->second);
            temp.push_back(i);
            break;
        }
        else
        {
            Map.insert(pair<int,int>(nums[i], i));
        }
    }
    return temp;
}

void arrayMain()
{
    cout << maxSumSubArray() << endl;
    subarraySum();
}