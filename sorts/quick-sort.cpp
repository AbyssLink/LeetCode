#include <cstdio>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
快速排序是交换排序的一种，快速排序的原理是：
将未排序元素根据一个作为基准的“主元”(Pivot)分为两个子序列，其中一个子序列的记录均大于主元，
而另一个子序列均小于主元，然后递归地对这两个子序列用相同的方法进行排序。

具体步骤：
1. 选择一个 pivot 并与最后一个元素交换，作为基准 A[r]。
(为了简单，选择序列的第一个元素作为pivot)
2. 设置指针 low 和 high，初值分别指向该序列的第一和倒数第二个元素。
3. high 从右向左扫描，若遇到比 pivot 小的元素则停止。
4. low 从左向右扫描，若遇到比 pivot 大的元素则停止。
5. 若 low 和 high 没有错排，swap(A[low], A[high])
5. 重复步骤 3 和 4,直至 high 和 low 错位，swap(A[low],
A[r])，一次划分完成，该序列分成了两个子序列。
6. 递归对两个划分后的子序列执行上述步骤。

 */

void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int low = l, high = r - 1, pivot = nums[low];
    swap(nums[low], nums[r]);
    while (true) {
        while (nums[high] >= pivot && high > l) {
            --high;
        }
        while (nums[low] <= pivot && low < r) {
            ++low;
        }
        if (low < high) {
            swap(nums[low], nums[high]);
        } else {
            break;
        }
    }
    swap(nums[low], nums[r]);
    quickSort(nums, l, low - 1);
    quickSort(nums, low + 1, r);
}

int main() {
    vector<int> nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};

    quickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}