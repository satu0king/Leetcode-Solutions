class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(366);
    unordered_set<int> set(days.begin(), days.end());
    for (int i = 1; i <= 365; i++) {
      if (set.count(i))
        dp[i] = min(min(id(i - 1, dp) + costs[0], id(i - 7, dp) + costs[1]),
                    id(i - 30, dp) + costs[2]);
      else
        dp[i] = dp[i - 1];
    }
    return dp.back();
  }

  int id(int i, vector<int> &dp) {
    if (i < 0)
      return 0;
    return dp[i];
  }
};
