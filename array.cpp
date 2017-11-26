//
// Created by ankit on 11/11/2017.
//
#include "common.h"
#include <vector>

// Find the maximum value subarray
int maxSubArray()
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

void arrayMain()
{
    cout << maxSubArray() << endl;
    subarraySum();
}