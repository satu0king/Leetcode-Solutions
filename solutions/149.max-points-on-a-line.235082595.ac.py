from fractions import Fraction
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        ans = 0
        l = len(points)
        
        for i in range(l):
            d = {'x':1}
            same = 0
            x1, y1 = points[i]
            for j in range(i+1,l):
                x2, y2 = points[j]
                if x2 == x1 and y2 == y1:
                    same+=1
                    continue
                slope = None
                if x2 == x1:
                    slope = 'i'
                else:
                    slope = Fraction((y2-y1),(x2-x1))
                if slope not in d:
                    d[slope] = 1
                d[slope]+=1
            ans = max(ans, max(d.values()) + same)
        return ans
        
