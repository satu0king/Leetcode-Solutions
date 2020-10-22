class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        m = len(grid[0])
        
        maxTop = [[0 for _ in range(m)] for _ in range(n) ]
        maxBottom = [[0 for _ in range(m)] for _ in range(n) ]
        maxLeft = [[0 for _ in range(m)] for _ in range(n) ]
        maxRight = [[0 for _ in range(m)] for _ in range(n) ]
        
        for i in range(n):
            for j in range(m):
                if j==0:
                    maxLeft[i][j] = grid[i][j]
                else:
                    maxLeft[i][j] = max(grid[i][j], maxLeft[i][j-1])
           
            for j in range(m-1, -1, -1):
                if j==m-1:
                    maxRight[i][j] = grid[i][j]
                else:
                    maxRight[i][j] = max(grid[i][j], maxRight[i][j+1])
           
        for j in range(m):
            for i in range(n):
                if i==0:
                    maxTop[i][j] = grid[i][j]
                else:
                    maxTop[i][j] = max(grid[i][j], maxTop[i-1][j])
            for i in range(n-1,-1,-1):
                if i==n-1:
                    maxBottom[i][j] = grid[i][j]
                else:
                    maxBottom[i][j] = max(grid[i][j], maxBottom[i+1][j])
        
        ans = 0
        for i in range(n):
            for j in range(m):
                ans += min(maxBottom[0][j], maxRight[i][0]) - grid[i][j]
        
        return ans
