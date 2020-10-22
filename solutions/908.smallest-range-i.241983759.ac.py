class Solution(object):
    def smallestRangeI(self, A, K):
        return max(0, max(A) - min(A) - 2 * K)
        
