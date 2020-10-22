class Solution:
    def countAndSay(self, n: int) -> str:
        current = "1"
        
        def f():
            nonlocal current
            l = [[current[0],1]]
            
            for c in current[1:]:
                if l[-1][0] == c:
                    l[-1][1]+=1
                else:
                    l.append([c, 1])
            
            temp = ""
            
            for (c, count) in l:
                temp+= str(count) + c
            
            current = temp
        
        for i in range(n-1):
            f()
        
        return current
        
        
            
            
