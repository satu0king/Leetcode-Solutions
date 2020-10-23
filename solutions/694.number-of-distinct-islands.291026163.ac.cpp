class Solution {
public:
  int numDistinctIslands(vector<vector<int>> &grid) {
    set<vector<long long int>> s;

    int n = grid.size();
    if (!n)
      return s.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          int lj = j;
          int rj = j;
          int ui = i;
          int di = i;
          vector<vector<int>> copy(n, vector<int>(m));
          dfs(grid, copy, i, j, lj, rj, ui, di);
          vector<long long int> v;
          for (int ii = ui; ii <= di; ii++) {
            long long int t = 0;
            for (int jj = lj; jj <= rj; jj++) {
              t <<= 1;
              if (copy[ii][jj])
                t++;
            }
            v.push_back(t);
          }
          s.insert(v);
        }
      }
    return s.size();
  }

  void dfs(vector<vector<int>> &grid, vector<vector<int>> &copy, int i, int j,
           int &lj, int &rj, int &ui, int &di) {

    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m)
      return;

    if (!grid[i][j])
      return;

    grid[i][j] = 0;
    copy[i][j] = 1;

    lj = min(lj, j);
    rj = max(rj, j);
    ui = min(ui, i);
    di = max(di, i);
    dfs(grid, copy, i + 1, j, lj, rj, ui, di);
    dfs(grid, copy, i - 1, j, lj, rj, ui, di);
    dfs(grid, copy, i, j + 1, lj, rj, ui, di);
    dfs(grid, copy, i, j - 1, lj, rj, ui, di);
  }
};
