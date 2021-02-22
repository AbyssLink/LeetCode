class Solution:
    def combinationSum2(self, candidates: list, target: int) -> list:
        candidates.sort()
        result = []

        def dfs(candidates: list, target: int, path: list, result: list):
            if target == 0:
                result.append(path)
            for i in range(len(candidates)):
                if i > 0 and candidates[i] == candidates[i-1]:
                    continue
                if target - candidates[i] < 0:
                    break
                dfs(candidates[i+1:], target-candidates[i],
                    path + [candidates[i]], result)

        dfs(candidates, target, [], result)
        print(result)
        return result


if __name__ == "__main__":
    solution = Solution()
    solution.combinationSum2([2, 5, 2, 1, 2], 5)
    # solution.combinationSum([2, 3, 6, 7], 7)
    # solution.combinationSum([2, 3, 5], 8)
    # solution.combinationSum([1, 2, 3, 6, 7], 15)
    # solution.combinationSum([2], 1)
    # solution.combinationSum([1], 1)
