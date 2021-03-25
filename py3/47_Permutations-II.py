class Solution:
    def permuteUnique(self, nums: list) -> list:
        result = []

        def dfs(candidates: list, path: list, result: list):
            if len(candidates) == 0:
                result.append(path)
                return
            for i in range(len(candidates)):
                if i > 0 and candidates[i] == candidates[i-1]:
                    i += 1
                    continue
                candidates_copy = candidates.copy()
                candidates_copy.pop(i)
                dfs(candidates_copy, path + [candidates[i]], result)

        nums.sort()
        dfs(nums, [], result)
        print(result)
        return result


if __name__ == "__main__":
    solution = Solution()
    solution.permuteUnique([1, 1, 1, 1, 2])
    solution.permuteUnique([1, 2, 3])
    solution.permuteUnique([0, 1])
    solution.permuteUnique([1])
    solution.permuteUnique([])
