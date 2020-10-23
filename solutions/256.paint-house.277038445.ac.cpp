class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<int> dp(3);

    for (int i = 0; i < n; i++) {
      vector<int> dp_next(3);
      for (int j = 0; j < 3; j++)
        dp_next[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
      swap(dp, dp_next);
    }

    return min(min(dp[0], dp[1]), dp[2]);
  }
};
