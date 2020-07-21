#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth
largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

 */

void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int low = l, high = r - 1, pivot = nums[low];
    swap(nums[low], nums[r]);
    while (true) {
        while (nums[high] >= pivot && high > l) {
            --high;
        }
        while (nums[low] <= pivot && low < r) {
            ++low;
        }
        if (low < high) {
            swap(nums[low], nums[high]);
        } else {
            break;
        }
    }
    swap(nums[low], nums[r]);
    quickSort(nums, l, low - 1);
    quickSort(nums, low + 1, r);
}

int findKthLargest(vector<int> &nums, int k) {
    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    return nums[nums.size() - k];
}

int main() {
    vector<int> nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    vector<int> nums1 = {3, 3, 3, 3, 3};
    int k = findKthLargest(nums1, 3);
    printf("\n%d", k);

    return 0;
}