#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true,
otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

bool search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[l] == nums[mid]) {
            // unable to determine which interval is in increasing order
            l++;
        } else if (nums[mid] <= nums[r]) {
            // right interval is in increasing order
            if (target > nums[mid] && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            // left interval is in increasing order
            if (target < nums[mid] && target >= nums[l]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {5, 6, 6, 8, 0, 1, 2, 2};
    bool result = search(nums, 2);
    if (result) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}