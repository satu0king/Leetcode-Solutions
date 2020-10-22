class Solution(object):
    def arrayPairSum(self, nums):
        return sum(sorted(nums)[::2])
        """
        :type nums: List[int]
        :rtype: int
        """
        
