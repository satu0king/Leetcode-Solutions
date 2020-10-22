class Solution(object):
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        A.sort()
        l = 0
        r = len(A)-1
        ans = []
        B = sorted([ (v, i) for i,v in enumerate(B)], reverse = True)
        
        for v, _ in B:
            if A[r]>v:
                ans.append(A[r])
                r-=1
            else:
                ans.append(A[l])
                l+=1
        
        ans2=[0]*len(A)
        for i, (_, _i) in enumerate(B):
            ans2[_i] = ans[i]
        return ans2
