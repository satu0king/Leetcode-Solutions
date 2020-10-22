class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {}
        matches = {}
        for i, name in enumerate(list1):
            d[name] = i
        
        for i, name in enumerate(list2):
            if name in d:
                matches[name] = i + d[name]
        
        l = sorted(matches.items(), key = lambda x:x[1])
        ans = []
        
        for (res, sm) in l:
            if sm == l[0][1]:
                ans.append(res)
        return ans
