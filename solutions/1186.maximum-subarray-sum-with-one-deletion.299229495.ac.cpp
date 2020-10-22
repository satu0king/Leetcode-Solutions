class Solution {
public:
  int maximumSum(vector<int> &arr) {
    int n = arr.size();
    vector<vector<long long>> dp(n, vector<long long>(2, INT_MIN));
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      dp[i][0] = arr[i];

      if (i)
        dp[i][0] = max(dp[i][0], dp[i][0] + dp[i - 1][0]);

      if (i) {
        dp[i][1] = dp[i - 1][1] + arr[i];
        dp[i][1] = max(dp[i - 1][0], dp[i][1]);
      }

      ans = max(ans, dp[i][1]);
      ans = max(ans, dp[i][0]);
    }
    return ans;
  }
};
