class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        
        ans = []
        prevSum = 0
        
        for word in words:
            if len(ans) == 0 or len(ans[-1]) + prevSum + len(word)>maxWidth:
                ans.append([word]);
                prevSum = len(word)
            else:
                ans[-1].append(word)
                prevSum += len(word)
                
        def f(a):
            spaces = maxWidth - sum(map(len,a))
            ans = a[0]
            
            w = len(a) - 1
            
            if w == 0:
                ans+= " "*spaces
                return ans
            
            space = spaces//w
            rem = spaces%w
            
            for i in range(w):
                ans+= " "*space
                if i<rem:
                    ans+= " "
                ans+= a[i+1]
                
            return ans
        
        for i in range(len(ans)-1):
            ans[i] = f(ans[i])
        
        ans[-1] = " ".join(ans[-1])
        ans[-1] += " "*(maxWidth - len(ans[-1]))
        
        return ans
