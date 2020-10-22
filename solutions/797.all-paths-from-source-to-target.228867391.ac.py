class Solution(object):
    def allPathsSourceTarget(self, graph):
        N = len(graph)
        
        memo = {}

        def solve(node):
            
            if node in memo:
                return memo[node]
            
            if node == N-1: return [[N-1]]
            ans = []
            for nei in graph[node]:
                for path in solve(nei):
                    ans.append([node] + path)
            
            memo[node] = ans
            return ans

        return solve(0)
