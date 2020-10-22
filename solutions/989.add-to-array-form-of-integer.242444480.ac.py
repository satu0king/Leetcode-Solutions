class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        return map(int,list(str(int("".join(map(str,A)) ) + K)))
        
