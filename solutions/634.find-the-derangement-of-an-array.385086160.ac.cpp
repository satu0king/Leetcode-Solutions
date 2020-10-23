class Solution {
public:
  int findDerangement(int n) {
    if (n == 1)
      return 0;
    int dp[n + 1];
    dp[1] = 0;
    dp[2] = 1;
    const int MOD = 1e9 + 7;
    for (int i = 3; i <= n; i++) {
      dp[i] = (1LL * (i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }
    return dp[n];
  }
};
