class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int n = piles.size();

    for (int i = n - 2; i >= 0; i--)
      piles[i] += piles[i + 1];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return f(0, 1, dp, piles);
  }

  int f(int i, int m, vector<vector<int>> &dp, vector<int> &piles) {
    int n = piles.size();

    if (i >= n)
      return 0;

    if (i + m >= n)
      return piles[i];

    if (~dp[i][m])
      return dp[i][m];

    int ans = 0;

    for (int x = 1; x <= 2 * m && i + x <= n; x++)
      ans = max(ans, piles[i] - f(i + x, max(x, m), dp, piles));

    return dp[i][m] = ans;
  }
};
