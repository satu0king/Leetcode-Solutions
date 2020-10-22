class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        
        ans = []
        
        def f(word):
            if len(word)!= len(pattern):
                return False
            d={}
            done = set()
            for i, c in enumerate(word):
                if c in d:
                    if d[c]!=pattern[i]:
                        return False
                else:
                    if pattern[i] in done:
                        return False
                    done.add(pattern[i])
                    d[c] = pattern[i]
            
            return True
        for word in words:
            if f(word):
                ans.append(word)
        return ans
        
