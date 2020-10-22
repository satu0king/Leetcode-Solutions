class Solution {
public:
  bool stoneGame(vector<int> &piles) {

    int n = piles.size();

    vector<int> dp = piles;

    for (int d = 1; d < n; d++) {
      vector<int> dp_next(n);
      for (int i = 0; i + d < n; i++) {
        dp_next[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
      }
      dp = move(dp_next);
    }

    return dp[0] >= 0;
  }
};
