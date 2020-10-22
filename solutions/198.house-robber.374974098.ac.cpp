class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      // Lets rob i
      int ans1 = nums[i];
      if (i >= 2)
        ans1 += dp[i - 2]; // and rob i - 2 or before
      // Lets not rob i
      int ans2 = 0;
      if (i >= 1)
        ans2 += dp[i - 1]; // and rob i - 1 or before
      dp[i] = max(ans1, ans2);
    }
    return dp[n - 1];
  }
};

// robIndex(n)
// will call robIndex(n - 1) and robIndex(n - 2)
// robIndex(n - 1) will call robIndex(n - 2) and robIndex(n - 3)
// We are calling robIndex(n - 2) twice -> overhead
// every function call splits into 2, and this happens N times
// so complexity is 2 ^ N

// 100 1 1 100
