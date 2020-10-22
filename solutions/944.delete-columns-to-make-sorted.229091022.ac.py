class Solution(object):
    def minDeletionSize(self, A):
        ans = 0
        for col in zip(*A):
            if any(col[i] > col[i+1] for i in xrange(len(col) - 1)):
                ans += 1
        return ans
