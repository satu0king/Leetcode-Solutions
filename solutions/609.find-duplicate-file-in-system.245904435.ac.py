class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        d = collections.defaultdict(list)
        
        def f(file):
            file = file.split()
            directory = file[0]
            
            def g(file):
                i = file.index('(')
                fileName = file[:i]
                fileContent = file[i:]
                
                d[fileContent].append(directory + "/" + fileName)
            
            for fil in file[1:]:
                g(fil)
        
        for path in paths:
            f(path)
        
        ans = []
        for v in d.values():
            if(len(v) > 1):
                ans.append(v)
        return ans
