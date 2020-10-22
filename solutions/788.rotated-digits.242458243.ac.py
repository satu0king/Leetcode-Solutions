class Solution:
    def rotatedDigits(self, N: int) -> int:
        
        d = {
            "9":"6",
            "8":"8",
            "6":"9",
            "5":"2",
            "2":"5",
            "1":"1",
            "0":"0"
        }
        
        def f(n):
            n = str(n)
            m = ""
            for c in n:
                if c not in d: return False
                m+=d[c]
            
            return m!=n
        
        return sum(map(f, range(1, N+1)))
