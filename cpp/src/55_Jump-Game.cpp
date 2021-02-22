#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Greedy

// 2,3,1,1,4
// i = 0, step = nums[i] = 2;
// j = 1, i + j = 1, step = nums[i+j] = 3;
// k = 1, i + j + k = 2, step = nums[i+j+k] = 1;
// m = 1, i + j + k + m = 3, step = nums[i+j+k+m] = 1;

vector<int> input = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6,
                     3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0,
                     0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9,
                     3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4,
                     3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5,
                     8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};

vector<int> input2 = {0};

vector<int> input3 = {2, 0, 0};

bool canJump(vector<int> &nums) {
    int maxStep = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (maxStep < i)
            return false;
        maxStep = max(nums[i] + i, maxStep);
    }
    return maxStep >= nums.size() - 1;
}

int main() {
    bool ans = canJump(input2);
    printf("%d ", ans);
    return 0;
}