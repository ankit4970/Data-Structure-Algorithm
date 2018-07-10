//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_ARRAY_H
#define INTERVIEW_ARRAY_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ArrayClass
{
    int maxSumSubArray();
    int subarraySum();
    vector<int> twoSum(vector<int>& nums, int target);
public:
    void arrayMain();
};
#endif //INTERVIEW_ARRAY_H
