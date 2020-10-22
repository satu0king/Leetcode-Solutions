class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(p)
        p = collections.Counter(p)
        ans = []
        count = n
        for i, c in enumerate(s):
            if i >= n:
                if p[s[i-n]] >= 0:
                    count+=1
                else:
                    count-=1
                    
                p[s[i-n]]+=1
            
            if p[c] > 0:
                count-=1
            else:
                count+=1
            
            p[c]-=1
            
            if count == 0:
                ans.append(i-n+1)
            
            # print(p, count, i, c)
            
        
        return ans
