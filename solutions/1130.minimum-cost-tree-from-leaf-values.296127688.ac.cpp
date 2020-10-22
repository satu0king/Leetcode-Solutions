class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int n = arr.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    for (int i = 0; i < n; i++)
      dp[i][i].second = arr[i];

    for (int l = 1; l < n; l++) {
      for (int i = 0; i + l < n; i++) {
        dp[i][i + l].first = INT_MAX;
        for (int k = 0; k < l; k++) {
          int t = dp[i][i + k].first + dp[i + 1 + k][i + l].first +
                  dp[i][i + k].second * dp[i + 1 + k][i + l].second;
          int v = max(dp[i][i + k].second, dp[i + 1 + k][i + l].second);
          if (t < dp[i][i + l].first) {
            dp[i][i + l].first = t;
            dp[i][i + l].second = v;
          }
        }
      }
    }
    return dp[0][n - 1].first;
  }
};

// SEE SOLUTION, THIS IS NOT THE BEST
