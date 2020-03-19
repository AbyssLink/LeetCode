#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string input = "adada";

/*
https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this
string.
The substrings with different start indexes or end indexes are counted as
different substrings even they consist of same characters.

 */

int countSubstrings(string s) {
    int ans = 0;
    for (int center = 0; center <= 2 * s.size() - 1; center++) {
        int left = center / 2;
        int right = center / 2 + center % 2;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
    }
    return ans;
}

int main() {
    int ans = countSubstrings(input);
    printf("%d ", ans);
    return 0;
}