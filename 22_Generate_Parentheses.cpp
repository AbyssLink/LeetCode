#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void backtrack(vector<string> &ans, int n, string word, int open, int close) {
    if (word.length() == n * 2) {
        ans.push_back(word);
        return;
    }

    if (open < n)
        backtrack(ans, n, word + '(', open + 1, close);
    if (open > close)
        backtrack(ans, n, word + ')', open, close + 1);
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, n, "", 0, 0);
    return ans;
}

int main() {
    vector<string> ans = generateParenthesis(3);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%c ", ans[i][j]);
        }
        printf("\n");
    }
}