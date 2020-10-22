class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    vector<int> dp(2001);

    if (S < -1000)
      return 0;
    if (S > 1000)
      return 0;

    int o = 1000;

    dp[o] = 1;

    for (int n : nums) {
      vector<int> dp_next(2001);

      for (int i = 0; i < 2001; i++)
        if (dp[i]) {
          dp_next[i + n] += dp[i];
          dp_next[i - n] += dp[i];
        }

      swap(dp_next, dp);
    }

    return dp[S + o];
  }
};
