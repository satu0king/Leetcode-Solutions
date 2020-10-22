class Solution {
public:
  int findMaxForm(vector<string> &strs, int M, int N) {

    vector<vector<int>> dp(M + 1, vector<int>(N + 1));

    for (auto s : strs) {

      int count[2] = {0};

      for (char c : s)
        count[c - '0']++;

      int zeroes = count[0];
      int ones = count[1];

      for (int j = M; j >= zeroes; j--)
        for (int k = N; k >= ones; k--)
          dp[j][k] = max(dp[j][k], dp[j - zeroes][k - ones] + 1);
    }

    return dp[M][N];
  }
};
