class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        return max(map(len, "".join(map(str, nums)).split('0')))
        
