class Solution:
    def largestSumAfterKNegations(self, A: List[int], k: int) -> int:
        A.sort()
        for i, v in enumerate(A):
            if v<0:
                A[i] *= -1
                k-=1
            else:
                break
            
            if k == 0:
                break
        k%=2
        A.sort()
        if k:
            A[0]*=-1
        
        return sum(A)
