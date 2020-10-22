class Solution {
public:
  int numDistinct(string s, string t) {

    int n1 = s.size();
    int n2 = t.size();
    vector<vector<long long int>> DP(n2 + 1, vector<long long int>(n1 + 1, 0));
    for (int i = 0; i <= n1; i++)
      DP[0][i] = 1;

    for (int i = 1; i <= n2; i++)
      for (int j = 1; j <= n1; j++)
        if (s[j - 1] == t[i - 1])
          DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
        else
          DP[i][j] = DP[i][j - 1];
    return DP[n2][n1];
  }
};
