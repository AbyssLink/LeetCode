#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/longest-increasing-subsequence/

Given an unsorted array of integers, find the length of longest increasing
subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4. Note:

There may be more than one LIS combination, it is only necessary for you to
return the length. Your algorithm should run in O(n2) complexity. Follow up:
Could you improve it to O(n log n) time complexity?
 */

int lengthOfLIS(vector<int> &nums) {
    int max_length = 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }
    return max_length;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = lengthOfLIS(nums);
    printf("%d ", ans);
    return 0;
}