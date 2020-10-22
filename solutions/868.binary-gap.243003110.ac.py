class Solution:
    def binaryGap(self, N: int) -> int:
        
        N = bin(N)[2:]
        
        prev = None
        
        mx = 0
        for i, c in enumerate(N):
            if c == '1':
                if prev is not None:
                    mx = max(mx, i - prev)
                prev = i
        return mx
        
