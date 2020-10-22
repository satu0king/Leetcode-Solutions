class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    const long int p = 1e9 + 7;
    while (d--) {
      vector<int> dp_next(target + 1, 0);
      long long int s = 0;
      for (int j = 1; j <= target; j++) {
        s += dp[j - 1];
        if (j - f - 1 >= 0)
          s -= dp[j - f - 1];
        s += p;
        s %= p;
        dp_next[j] = s;
      }
      swap(dp_next, dp);
    }

    return dp[target];
  }
};
