class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() < 1)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    vector<int> temp = nums;
    temp.pop_back();
    int mx = _rob(temp);
    temp = nums;
    temp[0] = 0;
    return max(mx, _rob(temp));
  }

  int _rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);

    for (int i = 2; i < n; i++)
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

    return dp.back();
  }
};
