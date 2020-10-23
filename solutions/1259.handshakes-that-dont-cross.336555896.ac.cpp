class Solution {
public:
  int numberOfWays(int num_people) {
    vector<long> dp(num_people + 1);
    dp[0] = 1;
    dp[2] = 1;
    const int MOD = 1e9 + 7;
    for (int j = 4; j <= num_people; j += 2) {
      for (int k = 0; k + 2 <= j; k += 2) {
        dp[j] += dp[k] * dp[j - k - 2];
        dp[j] %= MOD;
      }
    }
    return dp[num_people];
  }
};
