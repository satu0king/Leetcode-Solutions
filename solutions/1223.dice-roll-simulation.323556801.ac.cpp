class Solution {
public:
  int dieSimulator(int n, vector<int> &rollMax) {
    vector<vector<int>> dp(n + 1, vector<int>(6));
    vector<int> sum(n + 1);

    sum[0] = 1;

    const int p = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 6; j++) {
        for (int k = i - 1; k >= 0 && i - k <= rollMax[j]; k--) {
          dp[i][j] += (sum[k] - dp[k][j] + p) % p;
          dp[i][j] %= p;
        }

        sum[i] += dp[i][j];
        sum[i] %= p;
      }
    }

    return sum[n];
  }
};
