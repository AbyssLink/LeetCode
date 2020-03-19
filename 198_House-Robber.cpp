#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> input = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int rob(vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int prev = nums[0];
    int cur = max(prev, nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        int tmp = cur;
        cur = max(nums[i] + prev, cur);
        prev = tmp;
    }
    return cur;
}

int main() {
    int ans = rob(input);
    printf("%d ", ans);
    return 0;
}