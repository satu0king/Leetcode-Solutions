class Solution {
public:
  int minCost(string s, vector<int> &cost) {
    vector<int> dp(26, 0);
    for (int i = 0; i < s.size(); i++) {
      vector<int> dp_next = dp;
      int minCost = INT_MAX;
      for (int j = 0; j < 26; j++) {
        dp_next[j] += cost[i];
        if (s[i] - 'a' != j)
          minCost = min(minCost, dp[j]);
      }
      dp_next[s[i] - 'a'] = min(dp_next[s[i] - 'a'], minCost);
      dp = move(dp_next);
    }

    return *min_element(dp.begin(), dp.end());
  }
};
