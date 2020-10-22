class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        lo, hi = 0, len(S)
        ans = []
        
        for c in S:
            if c =='I':
                ans.append(lo)
                lo+=1
            elif c =='D':
                ans.append(hi)
                hi-=1
        
        return ans +[lo]
                
        
