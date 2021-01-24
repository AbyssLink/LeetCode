class Solution:
    def restoreIpAddresses(self, s: str):
        range1 = [2, 3, 4, 5, 6]
        range2 = [1, 2, 3]
        ans = []
        len1 = len(s)
        for i in range1:
            j = len1 - i
            if j in range1:
                for m1 in range2:
                    n1 = i - m1
                    if n1 in range2:
                        for m2 in range2:
                            n2 = j - m2
                            if n2 in range2:
                                # print(m1, n1, m2, n2)
                                subans = ""
                                cnt = 0
                                s_copy = s
                                for lenint in [m1, n1, m2, n2]:
                                    substr = s_copy[0:lenint]
                                    s_copy = s_copy[lenint:]
                                    num = int(substr)
                                    if num >= 0 and num <= 255 and len(str(num)) == len(substr):
                                        cnt += 1
                                        if(cnt == 4):
                                            subans += substr
                                        else:
                                            subans += substr + "."
                                    else:
                                        continue
                                    if len(subans) == len(s) + 3:
                                        ans.append(subans)
        # print(ans)
        return ans


if __name__ == "__main__":
    # execute only if run as a script
    solution = Solution()
    ans = solution.restoreIpAddresses("25525511135")
    ans = solution.restoreIpAddresses("0000")
    ans = solution.restoreIpAddresses("1111")
    ans = solution.restoreIpAddresses("010010")
    ans = solution.restoreIpAddresses("101023")
