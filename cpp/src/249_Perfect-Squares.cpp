#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/perfect-squares/

Given a positive integer n, find the least number of perfect square numbers (for
example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

 */

int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    // 边界条件
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            // 状态转移方程
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        // printf("dp(%d) = %d\n", i, dp[i]);
    }
    return dp[n];
}

int main() {
    int n = 1234567;
    int ans = numSquares(n);
    printf("%d ", ans);
    return 0;
}