//
// Created by ankit on 1/19/2018.
//

#ifndef INTERVIEW_BACKTRACKING_H
#define INTERVIEW_BACKTRACKING_H

#include "common.h"
#include <vector>

class BackTrackingClass{

    void coinChange(int amount, vector<int>& coins);
    void coinChangeCombinations(int amount, vector<int>& coins);

    vector<vector<int>> subsets(vector<int>& nums);
    void subsetsUtil(vector<int>& nums, vector<vector<int>>& combs, int index, vector<int>& combinations);

    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    void subsetsDupUtil(vector<int>& nums, vector<vector<int>>& combs, int index, vector<int>& combinations);
public:
    void backTrackMain();
};
#endif //INTERVIEW_BACKTRACKING_H
