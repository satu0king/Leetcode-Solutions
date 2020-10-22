class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        s = sum(nums)
        
        a = 0 
        
        for i, n in enumerate(nums):
            
            if s - n -a == a:
                return i
            a+=n
        return -1
