class Solution {
public:
  int numMusicPlaylists(int N, int L, int K) {
    vector<vector<long>> dp(L + 1, vector<long>(N + 1));
    dp[0][0] = 1;

    const int MOD = 1e9 + 7;
    for (int u = 1; u <= N; u++) {
      for (int l = 1; l <= L; l++) {
        dp[l][u] = dp[l - 1][u - 1] * (N - u + 1);
        dp[l][u] += dp[l - 1][u] * max(0, u - K);
        dp[l][u] %= MOD;
      }
    }
    return dp[L][N];
  }
};
