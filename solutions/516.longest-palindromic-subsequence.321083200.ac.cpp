class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
      dp[i][i] = 1;

    int ans = 1;

    for (int i = 2; i <= n; i++) {
      for (int j = 0; j + i - 1 < n; j++) {
        int l = j;
        int r = j + i - 1;

        dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        if (s[l] == s[r])
          dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
        ans = max(ans, dp[l][r]);
      }
    }
    return ans;
  }
};
