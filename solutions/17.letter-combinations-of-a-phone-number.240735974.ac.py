class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        d = {
            2:"abc",
            3:"def",
            4:"ghi",
            5:"jkl",
            6:"mno", 
            7:"pqrs",
            8:"tuv",
            9:"wxyz"
        }
        
        if digits == "":
            return []
        
        ans = []
        current = []
        n = len(digits)
        i = 0
        
        def f(i):
            if i == n:
                ans.append("".join(current))
                return
            
            for c in d[int(digits[i])]:
                current.append(c)
                f(i+1)
                current.pop()
        
        f(0)
        
        return ans
