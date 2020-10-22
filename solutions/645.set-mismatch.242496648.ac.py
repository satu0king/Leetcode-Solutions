class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return (collections.Counter(nums).most_common(1)[0][0], (set(list(range(1, len(nums)+1))) - set(nums)).pop())
        
