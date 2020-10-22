class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        wordSet = set(wordDict)
        
        d = {}
        d[-1] = True
        
        def f(i):
            if i in d:
                return d[i]
            
            for word in wordSet:
                if len(word) <= i + 1 and s[i-len(word)+1:i+1] == word and d[i-len(word)]:
                    d[i] = True
                    return d[i]
            
            d[i] = False
            return d[i]
        
        for i in range(len(s)):
            f(i)
            
        print(d)
        
        return d[len(s)-1]
                    
                    
                    
