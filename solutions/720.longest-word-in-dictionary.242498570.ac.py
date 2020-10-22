class Solution:
    def longestWord(self, words: List[str]) -> str:
        
        word_set = set(words)
        
        ans = ""
        
        for word in word_set:
            
            flag = True
            for i in range(1, len(word)):
                if word[:i] not in word_set:
                    flag = False
                    break
            
            if flag:
                if len(word) > len(ans):
                    ans = word
                elif len(word) == len(ans) and word < ans:
                    ans = word
        
        return ans
        
        
        
