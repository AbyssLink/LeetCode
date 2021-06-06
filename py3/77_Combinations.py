class Solution:
    def combine(self, n: int, k: int):
        nums = []
        for i in range(1, n+1):
            nums.append(i)
        result = []

        def dfs(candidates: list, path: list, result: list):
            if len(path) == k:
                result.append(path)
                return
            elif len(path) > k:
                return
            elif len(path) < k:
                for i in range(len(candidates)):
                    dfs(candidates[i+1:], path + [candidates[i]], result)
        dfs(nums, [], result)
        return result


if __name__ == "__main__":
    solution = Solution()
    # solution.combine(4, 2)
    solution.combine(4, 3)
