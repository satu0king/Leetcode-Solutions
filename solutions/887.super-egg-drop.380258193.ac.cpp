class Solution {
public:
  int superEggDrop(int K, int N) {
    vector<int> dp(N + 1);
    iota(dp.begin(), dp.end(), 0);

    for (int k = 2; k <= K; k++) {
      vector<int> dp_next(N + 1);
      int z = 1;
      for (int i = 1; i <= N; i++) {
        while (z < i) {
          int currentCost = max(dp_next[i - z], dp[z - 1]);
          int nextCost = max(dp_next[i - (z + 1)], dp[(z + 1) - 1]);
          if (currentCost <= nextCost)
            break;
          z++;
        }
        dp_next[i] = 1 + max(dp_next[i - z], dp[z - 1]);
      }
      dp = move(dp_next);
    }

    return dp[N];
  }
};
