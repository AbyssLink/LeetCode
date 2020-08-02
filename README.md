# LeetCode

program training for LeetCode

| Number | name                           | link                                                         | solution                                                     |
| ------ | ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 347    | Top K Frequent Elements        | [link](https://leetcode.com/problems/top-k-frequent-elements/) | 1. 使用桶排序，为每个值设一个桶记录该值出现的次数<br />2. 对桶的频次进行排序，可以使用各类排序算法。这里选择再进行一次桶排序，把每个旧桶根据频次放在不同的新桶内<br /> |
| 322    | Coin Change                    | [link](https://leetcode.com/problems/coin-change/)           | 每个硬币可以使用无限多次，属于完全背包问题                   |
| 249    | Perfect Squares                | [link](https://leetcode.com/problems/perfect-squares/)       | 分割类型题，动态规划的状态转移方程不依赖相邻的位置，而是满足分割条件的位置。<br />本题 dp[0]=0; dp[i] = min(dp[i-1], dp[i-4], ...) |
| 300    | Longest Increasing Subsequence | [link](https://leetcode.com/problems/longest-increasing-subsequence/) | 子序列问题，动态规划 dp[i] 表示 i 结尾的子序列的性质（本题中表示最长子序列长度）<br />初始时 dp[i] = 1; dp[i] = max(dp[i], dp[j]+1) (if nums[i] > nums[j]) |
|        |                                |                                                              |                                                              |

