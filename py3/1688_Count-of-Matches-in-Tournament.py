class Solution:
    def numberOfMatches(self, n: int) -> int:
        matches = 0
        while n != 1:
            if n % 2 == 0:
                matches += n / 2
                n = n / 2
            if n % 2 == 1:
                matches += (n - 1) / 2
                n = (n - 1) / 2 + 1
        return int(matches)


if __name__ == "__main__":
    solution = Solution()
    print(solution.numberOfMatches(7))
    print(solution.numberOfMatches(14))
    print(solution.numberOfMatches(18))
    print(solution.numberOfMatches(30))
    print(solution.numberOfMatches(879))
