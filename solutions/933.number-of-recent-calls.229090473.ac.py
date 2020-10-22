class RecentCounter:

    def __init__(self):
        self.l1 = []

    def ping(self, t: int) -> int:
        l1 = self.l1
        l1.append(t)
        
        l = 0
        r = len(l1)
        ans = None
        while l<=r:
            mid = (l+r)//2
            if(l1[mid] >= t-3000):
                r = mid-1
                if ans is None or len(l1) - mid > ans:
                    ans = len(l1) - mid 
            else:
                l = mid+1
        return ans
        
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
