#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int dp(int n, int stair, map<int, int> &memo) {
    if (memo[n] > 0) {
        return memo[n];
    }
    if (n == stair) {
        return 1;
    }
    if (n > stair) {
        return 0;
    }
    memo[n] = dp(n + 1, stair, memo) + dp(n + 2, stair, memo);
    return memo[n];
}

int climbStairs(int n) {
    map<int, int> memo;
    int ans = dp(0, n, memo);
    return ans;
}

int main() {
    int ans = climbStairs(40);
    printf("%d ", ans);
    return 0;
}