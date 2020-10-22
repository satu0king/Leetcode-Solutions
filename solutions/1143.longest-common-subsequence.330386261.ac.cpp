class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for (int i = 0; i < n1; i++)
      for (int j = 0; j < n2; j++) {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

        if (text1[i] == text2[j])
          dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
      }
    return dp[n1][n2];
  }
};
