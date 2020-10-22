class Solution {
public:
  int maxNonOverlapping(vector<int> &nums, int target) {
    int ans = 0;
    int n = nums.size();
    vector<int> dp(n + 1);
    unordered_map<int, int> mp;
    mp[0] = -1;
    int s = 0;
    for (int i = 0; i < n; i++) {
      dp[i + 1] = dp[i];
      s += nums[i];
      if (mp.count(s - target)) {
        int j = mp[s - target];
        dp[i + 1] = max(dp[i + 1], dp[j + 1] + 1);
      }
      mp[s] = i;
    }
    return dp[n];
  }
};
