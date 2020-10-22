class Solution:
    def findLHS(self, nums: List[int]) -> int:
        c = collections.Counter(nums)
        ans  = 0
        
        for i in c:
            if i-1 in c:
                ans = max(ans, c[i] + c[i-1])
        
        return ans
