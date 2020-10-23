class Solution {
public:
  int longestLine(vector<vector<int>> &M) {
    int n = M.size();
    if (!n)
      return 0;
    int m = M[0].size();

    vector<vector<int>> dp(m + 2, vector<int>(4));
    vector<vector<int>> dp_next(m + 2, vector<int>(4));

    int ans = 0;

    const int RIGHT = 0;
    const int D = 1;
    const int AD = 2;
    const int DOWN = 3;

    for (auto &row : M) {
      for (int i = 1; i <= m; i++) {

        if (row[i - 1] == 0) {
          dp_next[i][0] = dp_next[i][1] = dp_next[i][2] = dp_next[i][3] = 0;
          continue;
        }

        dp_next[i][RIGHT] = dp_next[i - 1][RIGHT] + 1;
        dp_next[i][DOWN] = dp[i][DOWN] + 1;
        dp_next[i][D] = dp[i - 1][D] + 1;
        dp_next[i][AD] = dp[i + 1][AD] + 1;
        ans = max(ans, *max_element(dp_next[i].begin(), dp_next[i].end()));
      }
      // cout << ans << endl;
      swap(dp_next, dp);
    }

    return ans;
  }
};
