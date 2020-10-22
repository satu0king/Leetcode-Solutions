class Solution {
  unordered_map<int, unordered_set<int>> set1;

public:
  int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {

    vector<vector<bool>> set1(N, vector<bool>(N));

    for (auto &m : mines)
      set1[m[0]][m[1]] = 1;

    vector<vector<int>> dp(N, vector<int>(N));

    for (int i = 0; i < N; i++) {

      int count = 0;

      for (int j = 0; j < N; j++) {
        if (set1[i][j])
          count = 0;
        else
          count++;
        dp[i][j] = count;
      }
      count = 0;

      for (int j = N - 1; j >= 0; j--) {
        if (set1[i][j])
          count = 0;
        else
          count++;
        dp[i][j] = min(count, dp[i][j]);
      }
    }
    int ans = 0;
    for (int j = 0; j < N; j++) {

      int count = 0;

      for (int i = 0; i < N; i++) {
        if (set1[i][j])
          count = 0;
        else
          count++;
        dp[i][j] = min(count, dp[i][j]);
      }
      count = 0;

      for (int i = N - 1; i >= 0; i--) {
        if (set1[i][j])
          count = 0;
        else
          count++;
        dp[i][j] = min(count, dp[i][j]);
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};
