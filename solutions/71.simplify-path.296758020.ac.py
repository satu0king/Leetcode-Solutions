class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.split('/')
        result = []
        
        for p in path:
            if p == "." or p == '': continue
                
            if p == "..":
                if result: 
                    result.pop()
                continue
            
            result.append(p)
        
        result = "/" + "/".join(result)
        
        return result
        
