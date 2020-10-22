class Solution:
    def longestPalindrome(self, s: str) -> int:
        v = collections.Counter(s).values()
        ans = 1 if sum(map(lambda x: 1 if x%2 else 0, v)) > 0 else 0
        ans+= sum(map(lambda x: (x//2 )* 2, v))
        return ans
