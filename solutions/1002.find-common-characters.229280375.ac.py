class Solution:
    
    def commonChars(self, A):
        
        answer = collections.Counter(A[0])
        
        for word in A[1:]:
            temp = collections.Counter(word)
            for c in answer:
                if c in temp:
                    answer[c] = min(answer[c], temp[c])
                else:
                    answer[c] = 0
        
        ans = []
        for k, v in answer.items():
            ans.extend([k]*v)
        return ans
        
