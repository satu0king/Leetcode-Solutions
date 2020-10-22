class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int n = grid.size();
    if (!n)
      return grid;
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int z = (i * m + j + k) % (n * m);
        int ii = z / m;
        int jj = z % m;
        ans[ii][jj] = grid[i][j];
      }

    return ans;
  }
};
