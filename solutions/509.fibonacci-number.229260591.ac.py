class Solution:
    
    d = {1:1, 0:0}
    
    def fib(self, N: int) -> int:
        if N not in self.d:
            self.d[N] = self.fib(N-1) + self.fib(N-2) 
        
        return self.d[N] 
        
