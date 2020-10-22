class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    vector<int> lookup(10001);

    for (int n : nums)
      lookup[n]++;

    vector<int> dp(10001);

    for (int i = 1; i < 10001; i++) {
      dp[i] = dp[i - 1];
      dp[i] = max(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + lookup[i] * i);
    }

    return dp[10000];
  }
};
