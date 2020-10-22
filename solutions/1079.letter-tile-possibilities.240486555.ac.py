from functools import reduce
class Solution:
    def numTilePossibilities(self, tiles):
        
        counter = collections.Counter(tiles)
        
        v = list(counter.values())
        n = len(v)
        l = []
        
        ans = 0
        def f(i = 0):
            if i == n:
                nonlocal ans
                ans += math.factorial(sum(l)) / reduce(lambda x, y: x*y, map(math.factorial, l))
                return
            for j in range(v[i]+1):
                
                l.append(j)
                f(i+1)
                l.pop()
            
        f()
        return  int(ans - 1)
