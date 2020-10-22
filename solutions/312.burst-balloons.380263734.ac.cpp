class Solution {

public:
  int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int l = 2; l < n; l++) {
      for (int i = 0; i + l < n; i++) {
        for (int j = i + 1; j < i + l; j++) {
          dp[i][i + l] = max(dp[i][i + l], nums[i] * nums[j] * nums[i + l] +
                                               dp[i][j] + dp[j][i + l]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
