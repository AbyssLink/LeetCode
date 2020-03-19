#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. For every numbers i in the
range 0 ≤ i ≤ num, calculate the number of 1's in their binary representation
and return them as an array.
*/

/*
i   bit     1's     i&(i-1)
0   0000    0
1   0001    1       0
2   0010    1       0
3   0011    2       1
4   0100    1       0
5   0101    2       1
6   0110    2       1
7   0111    3       2
8   1000    1       0
9   1001    2       1
10  1010    2       1
 */

int countSetBits(int num) {
    int n = 0;
    while (num) {
        n += num & 1;
        num >>= 1;
    }
    return n;
}

vector<int> countBits(int num) {
    vector<int> ans;
    for (int i = 0; i <= num; i++) {
        if (i == 0) {
            ans.push_back(0);
        } else {
            ans.push_back(countSetBits(i));
        }
    }
    return ans;
}

int main() {
    vector<int> ans = countBits(10);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}