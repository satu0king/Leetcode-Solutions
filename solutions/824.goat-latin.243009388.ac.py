class Solution:
    def toGoatLatin(self, S: str) -> str:
        
        S = S.split()
        
        vowels = set("aeiouAEIOU")
        
        def f(i, word):
            if word[0] in vowels:
                word += "ma"
            else:
                word = word[1:] + word[0] + "ma"
            word += "a" * i
            
            return word
            
        
            
        return " ".join([ f(i+1, w) for i, w in enumerate(S)])
