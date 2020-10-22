class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        return tuple(sorted(A)) == tuple(A) or tuple(sorted(A, reverse=True)) == tuple(A)
