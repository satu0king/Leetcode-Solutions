class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d)
      return -1;
    vector<vector<int>> dp(
        d + 1, vector<int>(n + 1, accumulate(jobDifficulty.begin(),
                                             jobDifficulty.end(), 0)));
    dp[0][0] = 0;

    for (int i = 1; i <= d; i++) {
      for (int j = n; j >= 1; j--) {
        int difficulty = 0;
        for (int k = j; k >= 1; k--) {
          difficulty = max(difficulty, jobDifficulty[k - 1]);
          dp[i][j] = min(dp[i][j], difficulty + dp[i - 1][k - 1]);
        }
      }
    }

    return dp[d][n];
  }
};
