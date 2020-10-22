class Solution {
public:
  int numberOfArrays(string s, int k) {
    vector<long> dp(s.size() + 1);
    int n = s.size();
    dp[0] = 1;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      for (int j = i; j >= 0 && j + 12 >= i; j--) {
        if (s[j] == '0')
          continue;
        long t = stol(s.substr(j, i - j + 1));
        if (t <= k)
          dp[i + 1] += dp[j];
        else
          break;

        dp[i + 1] %= MOD;
      }
    }

    return dp[n];
  }
};
