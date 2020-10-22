class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
      vector<int> dp_next(n);
      for (int j = 0; j < n; j++) {
        dp_next[j] += dp[j];
        if (j)
          dp_next[j] += dp_next[j - 1];
      }
      swap(dp, dp_next);
    }

    return dp[n - 1];
  }
};
