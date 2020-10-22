class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int t1 = i ? mat[i - 1][j] : 0;
        int t2 = j ? mat[i][j - 1] : 0;
        int t3 = i && j ? mat[i - 1][j - 1] : 0;

        mat[i][j] += t1 + t2 - t3;
      }

    vector<vector<int>> ans(n, vector<int>(m));

    auto f = [&](int x, int y) {
      if (x < 0 || y < 0)
        return 0;

      x = min(n - 1, x);
      y = min(m - 1, y);

      return mat[x][y];
    };

    auto f2 = [&](int x1, int y1, int x2, int y2) {
      int ans = f(x2, y2);

      ans -= f(x1 - 1, y2);
      ans -= f(x2, y1 - 1);
      ans += f(x1 - 1, y1 - 1);

      return ans;
    };

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ans[i][j] = f2(i - K, j - K, i + K, j + K);
      }

    return ans;
  }
};
