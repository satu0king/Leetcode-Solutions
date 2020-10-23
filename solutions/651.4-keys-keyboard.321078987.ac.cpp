class Solution {
public:
  int maxA(int N) {
    vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++) {
      dp[i] = dp[i - 1] + 1;
      for (int j = i - 3; j >= 1 && j >= i - 5; j--) {
        dp[i] = max(dp[i], dp[j] * (i - j - 1));
      }
    }

    return dp[N];
  }
};
