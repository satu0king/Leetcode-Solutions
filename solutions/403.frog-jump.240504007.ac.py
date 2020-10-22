class Solution:
    def canCross(self, stones: List[int]) -> bool:
        d = set()
        mp = {}
        
        if len(stones) == 1:
            return true
        
        if stones[1] != stones[0] + 1:
            return False
        
        for i, v in enumerate(stones):
            mp[v] = i
        
        
        def f(i, k):
            if i == len(stones)-1:
                return True
            
            
            if (i, k) in d:
                return False
            
            
            
            d.add((i,k))
            
            p = stones[i]
            
            for j in [-1, 0, 1]:
                _p = p + k + j
                if _p in mp:
                    if f(mp[_p], k + j):
                        return True
            
            return False
                
        return f(1,1)
