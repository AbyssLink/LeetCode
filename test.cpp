#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<long, long> memo;
    memo.insert({1, 10});
    printf("%ld ", memo[3]);
    return 0;
}