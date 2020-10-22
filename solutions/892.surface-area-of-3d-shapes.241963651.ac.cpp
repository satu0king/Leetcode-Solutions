class Solution {
public:
  int surfaceArea(vector<vector<int>> grid) {
    int res = 0, n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j])
          res += grid[i][j] * 4 + 2;
        if (i)
          res -= min(grid[i][j], grid[i - 1][j]) * 2;
        if (j)
          res -= min(grid[i][j], grid[i][j - 1]) * 2;
      }
    }
    return res;
  }
};
