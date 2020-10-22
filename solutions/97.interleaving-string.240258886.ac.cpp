class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {

    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();

    if (n1 + n2 != n3)
      return false;

    vector<vector<bool>> dp(n3 + 1, vector<bool>(n3 + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n3; i++) {
      char c = s3[i - 1];
      for (int j = 0; j <= n1 && j < i; j++) {
        int k = (i - j);
        if (k > n2)
          continue;
        if (s2[k - 1] == c && dp[j][k - 1])
          dp[j][k] = true;
      }

      for (int j = 0; j <= n2 && j < i; j++) {
        int k = (i - j);
        if (k > n1)
          continue;
        if (s1[k - 1] == c && dp[k - 1][j])
          dp[k][j] = true;
      }
    }

    return dp[n1][n2];
  }
};
