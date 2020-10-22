class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> dp;

    int c = 0;
    int ans = 0;

    dp[0] = -1;

    for (int i = 0; i < n; i++) {
      c += nums[i] ? 1 : -1;
      if (dp.count(c))
        ans = max(ans, i - dp[c]);
      else
        dp[c] = i;
    }

    return ans;
  }
};
