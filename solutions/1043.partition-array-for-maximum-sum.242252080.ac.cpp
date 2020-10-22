class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    int n = A.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      int mx = 0;
      int j = i;
      int t = K;
      while (t-- && j) {
        mx = max(mx, A[j - 1]);
        dp[i] = max(dp[i], dp[j - 1] + mx * (i - j + 1));
        j--;
      }
    }

    return dp.back();
  }
};
