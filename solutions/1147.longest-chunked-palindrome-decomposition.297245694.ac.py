from functools import lru_cache
class Solution:
    def longestDecomposition(self, text: str) -> int:
       
        @lru_cache(None)
        def dp(i,j):
            if i > j:
                return 0
            if i == j:
                return 1
            ans = 1
            k = 0
            while i+k< j-k:
                if text[i:i+k+1] == text[j-k:j+1]:
                    ans = max(ans,2+dp(i+k+1,j-k-1))
                k += 1
            return ans
        
        return dp(0,len(text)-1)
        
