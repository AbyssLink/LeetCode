#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> input = {1, 3, 1, -1, 3};

int singleNumber(vector<int> &nums) {
    vector<int> nums_single;
    for (int i = 0; i < nums.size(); i++) {
        if (nums_single.size() == 0) {
            nums_single.push_back(nums[i]);
        } else {
            int size = nums_single.size();
            int j = 0;
            bool duplicate = false;
            for (; j < size; j++) {
                if (nums_single[j] == nums[i]) {
                    duplicate = true;
                    nums_single.erase(nums_single.begin() + j);
                }
            }
            if (duplicate == false) {
                nums_single.push_back(nums[i]);
            }
        }
    }
    return nums_single[0];
}

int main() {
    int ans = singleNumber(input);
    printf("%d ", ans);
    return 0;
}