int f(int i, int j, vector<vector<int>> &dp, string &word1, string &word2) {
  int n = word1.size();
  int m = word2.size();
  if (i == n) {
    return (m - j);
  }
  if (j == m) {
    return (n - i);
  }

  // Cache
  if (dp[i][j] != -1)
    return dp[i][j];

  int ans = 1 + f(i + 1, j, dp, word1, word2);       // Delete word1[i]
  ans = min(ans, 1 + f(i, j + 1, dp, word1, word2)); // Add word2[j]
  ans = min(ans, 1 + f(i + 1, j + 1, dp, word1,
                       word2)); // Replace word1[i] with word2[j]

  if (word1[i] == word2[j]) {
    ans = min(ans, f(i + 1, j + 1, dp, word1, word2));
  }
  return dp[i][j] = ans;
}

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // dp[i][j] is minimum cost to match word1 upto i index with word2 upto j
    // index final answer is dp[n-1][m-1]
    return f(0, 0, dp, word1, word2);
  }
};
