class Solution(object): 
    def powerfulIntegers(self, x, y, bound):
        ans = set()
        # 2**18 > bound
        for i in xrange(100):
            for j in xrange(100):
                v = x**i + y**j
                if v <= bound:
                    ans.add(v)
        return list(ans)
