class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        return len(A) == len(B) and A in B + B
