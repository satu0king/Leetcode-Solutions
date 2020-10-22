class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        t = A
        ans = 1
        while len(t) < len(B):
            t = t + A
            ans += 1
        
        if B in t:
            return ans
        
        t = t + A
        ans += 1
        
        if B in t:
            return ans
        
        return -1
        
