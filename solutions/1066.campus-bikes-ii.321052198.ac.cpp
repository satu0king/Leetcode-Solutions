class Solution {

public:
  int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
    vector<int> dp(1024, -1);
    return f(workers, bikes, dp);
  }

  int f(vector<vector<int>> &workers, vector<vector<int>> &bikes,
        vector<int> &dp, int mask = 0, int i = 0) {

    if (~dp[mask])
      return dp[mask];

    int w = workers.size();
    int b = bikes.size();

    if (i >= w)
      return 0;

    int ans = INT_MAX;

    for (int j = 0; j < b; j++)
      if (!(mask & (1 << j))) {
        mask |= (1 << j);
        ans = min(ans, f(workers, bikes, dp, mask, i + 1) +
                           dist(bikes[j], workers[i]));
        mask &= ~(1 << j);
      }

    return dp[mask] = ans;
  }

  int dist(vector<int> &bike, vector<int> &worker) {
    return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
  }
};
