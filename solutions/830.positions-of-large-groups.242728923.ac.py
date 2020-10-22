class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """        
        if not S:
            return [[]]
        
        l = 0 
        r = 0
        
        ans = []
        
        for i in range(1, len(S)):
            if S[i] == S[l]:
                r = i
            else:
                
                if r - l + 1 >=3:
                    ans.append( [l, r])
                
                l = i
                r = i 
        
        if r - l + 1 >=3:
            ans.append( [l, r])
            
#         ans.sort(reverse = True)
        return ans
        
