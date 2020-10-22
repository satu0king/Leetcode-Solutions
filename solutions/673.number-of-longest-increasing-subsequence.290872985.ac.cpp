class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> dp(n, make_pair(1, 1));
    int mxx = 1;

    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i])
          mx = max(mx, dp[j].first);
      }

      mxx = max(mxx, mx + 1);
      int t = 0;

      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && dp[j].first == mx)
          t += dp[j].second;
      }

      dp[i] = make_pair(mx + 1, max(1, t));
    }

    int ans = 0;

    for (auto p : dp)
      if (p.first == mxx)
        ans += p.second;

    return ans;
  }
};
