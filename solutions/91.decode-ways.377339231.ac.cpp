class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      int a = s[i] - '0';

      if (a > 0)
        dp[i] = dp[i + 1];
      if (i == n - 1)
        continue;
      int b = s[i + 1] - '0';
      if (a > 0 && (a * 10 + b) <= 26 && (a * 10 + b) > 0) {
        dp[i] += dp[i + 2];
      }
    }
    return dp[0];
  }
};
