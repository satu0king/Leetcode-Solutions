class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<bool> dp(sum + 1);
    dp[0] = true;

    for (int s : stones)
      for (int i = sum; i >= 1; i--)
        if (i >= s)
          dp[i] = dp[i] || dp[i - s];

    int ans = sum;

    for (int i = 0; i <= sum; i++)
      if (dp[i])
        ans = min(ans, abs((sum - i) - i));
    return ans;
  }
};
