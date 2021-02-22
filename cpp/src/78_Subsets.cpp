#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> input{1, 2, 7, 8};

/*
https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets
(the power set).
Note: The solution set must not contain duplicate subsets.
 */

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> first;
    ans.push_back(first);
    for (int i = 0; i < nums.size(); i++) {
        int size = ans.size();
        for (int j = 0; j < size; j++) {
            vector<int> cur = ans[j];
            cur.push_back(nums[i]);
            ans.push_back(cur);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> result = subsets(input);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}