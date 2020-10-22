class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):
            grid[i] = [0] + grid[i] + [0]
        
        grid = [[0] * len(grid[0])] + grid + [[0] * len(grid[0])]
        
        ans = 0
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans+= 4 - (grid[i+1][j] + grid[i][j+1] + grid[i][j-1] + grid[i-1][j])
        return ans
