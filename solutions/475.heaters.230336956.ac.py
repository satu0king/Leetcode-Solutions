class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        l = 0
        r = 10**9
        
        houses.sort()
        heaters.sort()
        
        ans = None
        
        def f(m):
            i = 0
            for house in houses:
                while abs(house - heaters[i])>m:
                    i+=1
                    if i == len(heaters):
                        return False
                
            return True
            
        while l<=r:
            m = (l+r)//2
            if f(m):
                ans = m
                r = m-1
            else:
                l = m+1
        return ans
        
