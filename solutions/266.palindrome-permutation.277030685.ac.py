class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        s = collections.Counter(s)
        
        odd = 0
        
        for c in s:
            odd += s[c] % 2
        
        return odd <= 1
