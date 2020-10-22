class Solution {
public:
  vector<vector<bool>> vis;
  int n, m;
  int component_size = 0;
  int ans = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  vector<vector<int>> adj;
  bool isValid(int i, int j) {
    if (i >= n or i < 0)
      return false;
    if (j >= m or j < 0)
      return false;
    if (adj[i][j] == 0)
      return false;
    return true;
  }
  void dfsUtil(int x, int y) {
    if (!isValid(x, y))
      return;
    if (vis[x][y])
      return;
    vis[x][y] = 1;
    component_size++;
    for (int i = 0; i < 4; i++) {
      dfsUtil(x + dx[i], y + dy[i]);
    }
  }
  void dfs() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] == 0) {
          component_size = 0;
          dfsUtil(i, j);
          ans = max(ans, component_size);
        }
      }
    }
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    n = grid.size();
    if (n == 0)
      return 0;
    m = grid[0].size();
    if (m == 0)
      return 0;
    vis.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
      vis[i].resize(m);
      adj[i].resize(m);
    }
    adj = grid;
    for (int i = 0; i < n; i++) {
      vis[i] = vector<bool>(m, false);
    }

    dfs();
    return ans;
  }
};
