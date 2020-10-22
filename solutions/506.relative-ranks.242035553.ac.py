class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        
        for i, v in enumerate(nums):
            nums[i] = (v, i)
        nums = sorted(nums , reverse = True)
        
        ans = [None] * len(nums)
        
        for i, (v, x) in enumerate(nums):
            if i == 0:ans[x] = "Gold Medal"
            elif i == 1:ans[x] = "Silver Medal"
            elif i == 2:ans[x] = "Bronze Medal"
            else:ans[x] = str(i+1)
        
        return ans
