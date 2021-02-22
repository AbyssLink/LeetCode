class Solution:
    def permute(self, nums: list) -> list:
        result = []

        def dfs(candidates: list, path: list, result: list):
            if len(candidates) == 0:
                result.append(path)
                return
            for i in range(len(candidates)):
                candidates_copy = candidates.copy()
                candidates_copy.pop(i)
                dfs(candidates_copy, path + [candidates[i]], result)

        dfs(nums, [], result)
        print(result)
        return result


if __name__ == "__main__":
    solution = Solution()
    solution.permute([1, 1, 2])
    solution.permute([1, 2, 3])
    solution.permute([0, 1])
    solution.permute([1])
    solution.permute([])
