class Solution {
public:
  int dfs(vector<vector<int>> &g, int i, int j) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] <= 0)
      return 0;
    g[i][j] = -g[i][j];
    auto res = max({dfs(g, i + 1, j), dfs(g, i, j + 1), dfs(g, i - 1, j),
                    dfs(g, i, j - 1)});
    g[i][j] = -g[i][j];
    return g[i][j] + res;
  }
  int getMaximumGold(vector<vector<int>> &grid, int res = 0) {
    for (auto i = 0; i < grid.size(); ++i)
      for (auto j = 0; j < grid[i].size(); ++j)
        res = max(res, dfs(grid, i, j));
    return res;
  }
};
