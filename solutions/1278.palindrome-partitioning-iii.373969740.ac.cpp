class Solution {
public:
  int palindromePartition(string s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
    dp[0][0] = 0;
    for (int f = 1; f <= k; f++) {
      for (int i = 0; i < n; i++) {
        int c = 0;
        // odd
        for (int j = 0; i - j >= 0 && i + j < n; j++) {
          if (s[i - j] != s[i + j])
            c++;
          dp[i + j + 1][f] = min(dp[i + j + 1][f], dp[i - j][f - 1] + c);
        }
        // even
        c = 0;
        for (int j = 0; i - j - 1 >= 0 && i + j < n; j++) {
          if (s[i - j - 1] != s[i + j])
            c++;
          dp[i + j + 1][f] = min(dp[i + j + 1][f], dp[i - j - 1][f - 1] + c);
        }
      }
    }
    return dp[n][k];
  }
};
