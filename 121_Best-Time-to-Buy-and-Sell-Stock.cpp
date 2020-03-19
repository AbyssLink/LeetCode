#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> input = {};

int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
        return 0;
    }
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            profit = max(profit, prices[i] - minPrice);
        } else {
            minPrice = min(minPrice, prices[i]);
        }
    }
    return profit;
}

int main() {
    int ans = maxProfit(input);
    printf("%d ", ans);
    return 0;
}