class Solution:
    def findTheDifference(self, s, t):
        return (collections.Counter(t) - collections.Counter(s)).keys()[0]
