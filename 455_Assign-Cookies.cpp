#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/assign-cookies/

Assume you are an awesome parent and want to give your children some cookies.
But, you should give each child at most one cookie. Each child i has a greed
factor gi, which is the minimum size of a cookie that the child will be content
with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j
to the child i, and the child i will be content. Your goal is to maximize the
number of your content children and output the maximum number.

Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children
are 1, 2, 3. And even though you have 2 cookies, since their size is both 1, you
could only make the child whose greed factor is 1 content. You need to output 1.

 */

int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    for (; i < g.size() && j < s.size();) {
        if (g[i] <= s[j]) {
            i++;
        }
        j++;
    }
    return i;
}

int main() {
    vector<int> sizes = {3, 2, 1};
    vector<int> greeds = {5, 6, 1, 2};
    int num;
    num = findContentChildren(greeds, sizes);
    printf("%d\n", num);

    return 0;
}