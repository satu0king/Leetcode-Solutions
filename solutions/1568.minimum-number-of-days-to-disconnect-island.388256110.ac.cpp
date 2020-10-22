class Solution {
public:
  int minDays(vector<vector<int>> &grid) {
    if (isDisconnected(grid))
      return 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          grid[i][j] = 0;
          if (isDisconnected(grid))
            return 1;
          grid[i][j] = 1;
        }
      }

    return 2;
  }

  bool isDisconnected(vector<vector<int>> grid) {
    int c = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (dfs(grid, i, j))
          c++;
    return c == 0 || c > 1;
  }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0)
      return 0;
    grid[i][j] = 0;
    int ret = 1;
    ret += dfs(grid, i + 1, j);
    ret += dfs(grid, i - 1, j);
    ret += dfs(grid, i, j + 1);
    ret += dfs(grid, i, j - 1);
    return ret;
  }
};
