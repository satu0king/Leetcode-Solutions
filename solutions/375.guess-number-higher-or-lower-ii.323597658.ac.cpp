class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int d = 1; d < n; d++) {
      for (int i = 1; i <= n - d; i++) {
        dp[i][i + d] = INT_MAX;
        for (int g = i; g <= i + d; g++)
          dp[i][i + d] =
              min(dp[i][i + d], g + max(dp[i][g - 1], dp[g + 1][i + d]));
      }
    }

    return dp[1][n];
  }
};
