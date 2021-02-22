class Solution:
    def combinationSum(self, candidates: list, target: int):
        result = []
        candidates.sort()

        def dfs(candidates: list, id: int, target: int, path: list, result: list):
            print('path = ', path)
            for i in range(len(candidates[id:])):
                if target == 0:
                    result.append(path)
                    return
                elif target - candidates[i+id] < 0:
                    return
                dfs(candidates, i+id, target -
                    candidates[i+id], path+[candidates[i+id]], result)

        dfs(candidates, 0, target, [], result)
        print(result)
        return result


if __name__ == "__main__":
    solution = Solution()
    solution.combinationSum([5, 10, 8, 4, 3, 12, 9], 27)
    # solution.combinationSum([2, 3, 6, 7], 7)
    # solution.combinationSum([2, 3, 5], 8)
    # solution.combinationSum([1, 2, 3, 6, 7], 15)
    # solution.combinationSum([2], 1)
    # solution.combinationSum([1], 1)
