class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c = collections.Counter(nums1)
        ans = []
        for n in nums2:
            if c[n] > 0:
                c[n]-=1
                ans.append(n)
        return ans
