#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold
additional elements from nums2. Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]


Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

 */

// Brute Force
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // use three pointer: i for nums1, j for nums2, p for point out copy postion
    int i = m - 1, j = n - 1, p = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[p] = nums1[i];
            --i;
            --p;
        } else {
            nums1[p] = nums2[j];
            --j;
            --p;
        }
    }
    while (j >= 0) {
        nums1[p] = nums2[j];
        --j;
        --p;
    }
}

int main() {
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++) {
        printf("%d ", nums1[i]);
    }
    return 0;
}