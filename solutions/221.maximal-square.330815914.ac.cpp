class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int ans = 0;
    int n = matrix.size();
    if (!n)
      return 0;
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = i ? dp[i - 1][j] : 0;
        int y = j ? dp[i][j - 1] : 0;
        int z = i && j ? dp[i - 1][j - 1] : 0;

        if (matrix[i][j] == '1')
          dp[i][j] = min(min(x, y), z) + 1;

        ans = max(ans, dp[i][j]);
      }
    }
    return ans * ans;
  }
};
