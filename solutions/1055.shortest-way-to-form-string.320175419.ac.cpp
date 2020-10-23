class Solution {
public:
  int shortestWay(string source, string target) {

    int n = source.size();

    vector<vector<int>> dp(n + 1, vector<int>(26, -1));
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = dp[i + 1];
      dp[i][source[i] - 'a'] = i + 1;
    }

    int ans = 1;

    int current = 0;

    for (char c : target) {
      if (dp[current][c - 'a'] == -1) {
        ans++;
        current = 0;
      }
      if (~dp[current][c - 'a'])
        current = dp[current][c - 'a'];
      else
        return -1;
    }
    return ans;
  }
};
