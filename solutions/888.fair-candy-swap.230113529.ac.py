class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        n1 = sum(A)
        n2 = sum(B)
        A = set(A)
        B = set(B)
        
        for a in A:
            if (n2 - n1)//2 + a in B:
                return [a, (n2 - n1)//2 + a]
