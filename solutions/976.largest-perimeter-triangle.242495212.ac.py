class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0 
      
        A.sort()
        
        while(len(A) >=3):
            l1 = A[-1]
            l2 = A[-2]
            l3 = A[-3]
            if l2 + l3 > l1:
                return l1 + l2 + l3
            
            A.pop()
        
        return 0
