def isSorted(A):
    
    for i in range(0, len(A)-1):
        if A[i]>A[i+1]:
            return False
    return True

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
       
        for i in range(0, len(nums)-1):
            if nums[i]>nums[i+1]:
                t = nums[i]
                nums[i] = nums[i+1]
                if isSorted(nums[:i+1]) and isSorted(nums[i+1:]):
                    return True
                nums[i+1] = t
                nums[i] = t
                if isSorted(nums[:i+1]) and isSorted(nums[i+1:]):
                    return True
                return False
            
        
        return True
