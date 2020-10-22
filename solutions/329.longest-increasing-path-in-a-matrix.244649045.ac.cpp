class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (!n)
      return 0;
    int m = matrix[0].size();

    vector<vector<int>> ans(n, vector<int>(m, -1));

    int mx = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        mx = max(dfs(matrix, ans, i, j), mx);

    return mx;
  }

  int dfs(vector<vector<int>> &matrix, vector<vector<int>> &ans, int i, int j) {
    if (~ans[i][j])
      return ans[i][j];

    int v = matrix[i][j];

    int n = matrix.size();
    int m = matrix[0].size();

    ans[i][j] = 1;

    if (i && matrix[i - 1][j] > v)
      ans[i][j] = max(1 + dfs(matrix, ans, i - 1, j), ans[i][j]);

    if (j && matrix[i][j - 1] > v)
      ans[i][j] = max(1 + dfs(matrix, ans, i, j - 1), ans[i][j]);

    if (i != n - 1 && matrix[i + 1][j] > v)
      ans[i][j] = max(1 + dfs(matrix, ans, i + 1, j), ans[i][j]);

    if (j != m - 1 && matrix[i][j + 1] > v)
      ans[i][j] = max(1 + dfs(matrix, ans, i, j + 1), ans[i][j]);

    return ans[i][j];
  }
};
