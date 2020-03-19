#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/daily-temperatures/

Given a list of daily temperatures T, return a list such that, for each day in
the input, tells you how many days you would have to wait until a warmer
temperature. If there is no future day for which this is possible, put 0
instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 */

vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};

vector<int> dailyTemperatures(vector<int> &T) {
    vector<int> ans(T.size(), 0);
    // next[1] ~ next[100], 数组开大一些防止越界
    vector<int> next(101, INT_MAX);
    for (int i = T.size() - 1; i >= 0; i--) {
        int warmer_i = INT_MAX;
        for (int t = T[i] + 1; t <= 100; t++) {
            if (next[t] < warmer_i) {
                warmer_i = next[t];
            }
        }
        if (warmer_i < INT_MAX) {
            ans[i] = warmer_i - i;
        }
        next[T[i]] = i;
    }
    return ans;
}

int main() {
    vector<int> ans = dailyTemperatures(input);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}