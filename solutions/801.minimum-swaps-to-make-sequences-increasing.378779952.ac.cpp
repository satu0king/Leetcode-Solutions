class Solution {
public:
  int minSwap(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2, n + 1));
    dp[0] = {0, 1};
    for (int i = 1; i < n; i++) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1])
        dp[i][0] = min(dp[i][0], dp[i - 1][0]);

      if (A[i] > B[i - 1] && B[i] > A[i - 1])
        dp[i][0] = min(dp[i][0], dp[i - 1][1]);

      if (B[i] > A[i - 1] && A[i] > B[i - 1])
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);

      if (B[i] > B[i - 1] && A[i] > A[i - 1])
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);

      if (dp[i][0] == n + 1 && dp[i][1] == n + 1)
        return -1;
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
  }
};
