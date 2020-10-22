class Solution(object):
    def camelMatch(self, queries, pattern):
        """
        :type queries: List[str]
        :type pattern: str
        :rtype: List[bool]
        """
        def f(query):
            i = 0
            j = 0
            n1 = len(query)
            n2 = len(pattern)
            while i < n1 and j < n2:
                if query[i] == pattern[j]:
                    i+=1
                    j+=1
                elif query[i].islower():
                    i+=1
                else:
                    return False
            return j == n2 and query[i:].lower() == query[i:]
                
        
        return map(f, queries)
        
