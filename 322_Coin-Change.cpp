#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> coins = {1, 2, 5};
int amount = 204;

int coinChange(vector<int> &coins, int amount) {
    // 数组大小为 amount + 1, 初始值也为 amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 在求所有子问题 + 1 的最小值
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0)
                continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main() {
    int ans = coinChange(coins, amount);
    printf("%d", ans);
    return 0;
}