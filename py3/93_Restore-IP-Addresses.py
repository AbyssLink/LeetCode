class Solution:
    def restoreIpAddresses(self, s: str):
        res = []
        self.dfs(s, 4, [], res)
        # print(res)
        return res

    def dfs(self, s, level: int, path: list, res: list):
        if s == "" and len(path) == 4:
            res.append('.'.join(path))
            return
        # pruning, if not possible, then stop dfs down
        if level*3 < len(s) or level*1 > len(s):
            return
        for i in range(1, 4):
            if(i > len(s)):
                break
            number = int(s[:i])
            if str(number) == s[:i] and number <= 255 and number >= 0:
                # print('path = ', path)
                self.dfs(s[i:], level - 1, path + [s[:i]], res)


if __name__ == "__main__":
    solution = Solution()
    ans = solution.restoreIpAddresses("25525511135")
    ans = solution.restoreIpAddresses("24325678")
    ans = solution.restoreIpAddresses("0000")
    ans = solution.restoreIpAddresses("1111")
    ans = solution.restoreIpAddresses("010010")
    ans = solution.restoreIpAddresses("101023")
