class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        
        def keyFn(x):
            x = x.split()
            if x[1][0].isalpha():
                return (0, x[1:], x[0])
            return (1,)
                
        logs.sort(key = keyFn)
        return logs
