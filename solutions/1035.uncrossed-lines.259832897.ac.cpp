class Solution {
public:
  int maxUncrossedLines(vector<int> &A, vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (A[i - 1] == B[j - 1])
          dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
      }

    return dp[n1][n2];
  }
};
