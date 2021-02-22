#include <cstdio>
#include <iostream>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/candy/

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following
requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2
candies respectively.
 */

// use brute force
int candy(vector<int> &ratings) {
    int size = ratings.size();
    // init vector with value 1
    vector<int> num(size, 1);

    // traverse from left to right
    for (int i = 1; i < size; i++) {
        if (ratings[i] > ratings[i - 1]) {
            num[i] = num[i - 1] + 1;
        }
    }

    // traverse from right to left
    for (int i = size - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            num[i] = max(num[i + 1] + 1, num[i]);
        }
    }

    // return sum
    return accumulate(num.begin(), num.end(), 0);
}

int main() {
    vector<int> r = {1, 3, 4, 5, 2};
    int sum = candy(r);
    printf("%d\n", sum);

    return 0;
}