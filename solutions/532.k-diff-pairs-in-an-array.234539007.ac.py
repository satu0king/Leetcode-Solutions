class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        
        num_set = collections.Counter(nums)
        count = 0 
        
        for c in num_set:
            if k == 0:
                if num_set[c]>1:
                    count+=1
            elif k>0:
                if c+k in num_set:
                    count+=1
        return count
        
