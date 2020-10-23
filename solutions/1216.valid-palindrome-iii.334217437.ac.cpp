class Solution {
public:
  bool isValidPalindrome(string s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;

    for (int d = 1; d < n; d++) {
      for (int i = 0; i + d < n; i++) {
        int j = i + d;
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1] + 2;
        else
          dp[i][j] = max({dp[i + 1][j], dp[i][j - 1]});
      }
    }

    return dp[0][n - 1] + k >= n;
  }
};
