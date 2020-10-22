class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k)
      return false;

    int target = sum / k;
    int visited = 0;
    vector<int> dp(1 << nums.size(), -1);

    return f(nums, visited, k, target, dp);
  }

  bool f(vector<int> &nums, int visited, int k, int target, vector<int> &dp,
         int current = 0, int j = 0) {
    if (k == 0)
      return true;

    if (~dp[visited])
      return dp[visited];

    if (current == target)
      return dp[visited] = f(nums, visited, k - 1, target, dp);

    for (int i = j; i < nums.size(); i++) {
      if (!(visited & (1 << i)) && current + nums[i] <= target) {
        if (f(nums, visited | (1 << i), k, target, dp, current + nums[i],
              i + 1))
          return dp[visited] = true;
      }
    }

    return dp[visited] = false;
  }
};
