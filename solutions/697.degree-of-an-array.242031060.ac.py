class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        left = {}
        right = {}
        for i, x in enumerate(nums):
            if x not in left: left[x] = i
            right[x] = i
        
        degree = max(count.values())
        
        ans = len(nums)
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)
        return ans
