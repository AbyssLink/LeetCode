#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/top-k-frequent-elements/

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the
array's size. It's guaranteed that the answer is unique, in other words the set
of the top k frequent elements is unique. You can return the answer in any
order.
 */

vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> counts;
    int max_count = 0;
    for (int i = 0; i < nums.size(); i++) {
        counts[nums[i]]++;
        max_count = max(max_count, counts[nums[i]]);
    }
    vector<vector<int>> buckets(max_count + 1);
    for (auto it = counts.begin(); it != counts.end(); it++) {
        buckets[it->second].push_back(it->first);
    }
    vector<int> ans;
    for (int i = max_count; i >= 0 && ans.size() < k; --i) {
        for (int j = 0; j < buckets[i].size(); j++) {
            ans.push_back(buckets[i][j]);
            if (ans.size() == k) {
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 4, 5, 5, 5};
    int k = 3;
    vector<int> ans = topKFrequent(nums, k);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}