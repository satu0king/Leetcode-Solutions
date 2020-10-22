class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if A == B:
            return len(set(A)) != len(B)
        else:
            t = 0 
            temp_i = None
            for i, (a, b) in enumerate(zip(A, B)):
                if a!=b:
                    if t == 0:
                        temp_i = i
                        t += 1
                    elif t == 1:
                        return A[temp_i] == B[i] and B[temp_i] == A[i] and A[i+1:] == B[i+1:]
                    else:
                        return False
            return False
