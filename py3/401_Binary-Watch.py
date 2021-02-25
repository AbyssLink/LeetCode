class Solution:
    def readBinaryWatch(self, num: int):
        candidates = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        result = []

        if num == 0:
            return ['0:00']
        if num >= 10 or num < 0:
            return []

        def dfs(level: int, candidates: list, path: list, result: list):
            if level == num:
                time = self.path2time(path)
                if time == None:
                    return
                for t in result:
                    if t == time:
                        return
                result.append(time)
                return
            for i in range(len(candidates)):
                dfs(level+1, candidates[i+1:], path+[candidates[i]], result)
        dfs(0, candidates, [], result)
        print(result)
        return result

    def path2time(self, path: list):
        hs = [1, 2, 4, 8]
        ms = [1, 2, 4, 8, 16, 32]
        hours = minutes = 0
        for i in path:
            if i >= 0 and i <= 3:
                hours += hs[i]
            elif i >= 4 and i <= 9:
                minutes += ms[i-4]

        if minutes >= 60:
            return None
        if hours >= 12:
            return None
        if minutes < 10:
            return f"{hours}:0{minutes}"
        else:
            return f"{hours}:{minutes}"


if __name__ == "__main__":
    solution = Solution()
    solution.readBinaryWatch(1)
    solution.readBinaryWatch(2)
    solution.readBinaryWatch(3)
    solution.readBinaryWatch(4)
    solution.readBinaryWatch(4)
    solution.readBinaryWatch(10)
