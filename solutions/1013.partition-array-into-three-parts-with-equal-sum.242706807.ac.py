class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        print(sum(A))
        if(sum(A)%3):
            return False
        
        t = sum(A)//3
        print(t)
        
        l = None 
        sm = 0
        for i, n in enumerate(A):
            if sm == t and l is None:
                l = i
                break
                
            sm+=n
         
        sm = 0 
        r = None
        for i, n in enumerate(A[::-1]):
            if sm == t and r is None :
                r = i
                break
            sm+=n
        print(l, r, len(A))
        return l is not None and r is not None and (l + r) < len(A)
        
