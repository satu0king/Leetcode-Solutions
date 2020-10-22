class Solution {
public:
  string shortestCommonSupersequence(string s1, string s2) {

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }

    string ans = "";
    int i = n1;
    int j = n2;

    while (i || j) {
      if (!i || !j) {
        if (i)
          ans += s1[--i];
        else
          ans += s2[--j];
      } else if (s1[i - 1] == s2[j - 1]) {
        ans += s1[i - 1];
        i--;
        j--;
      } else if (dp[i][j - 1] + 1 == dp[i][j])
        ans += s1[--i];
      else
        ans += s2[--j];
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
