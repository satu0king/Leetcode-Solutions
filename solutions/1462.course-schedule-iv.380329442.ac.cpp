class Solution {
  bool dfs(vector<vector<int>> &g, vector<vector<int>> &dp, int a, int b) {
    if (~dp[a][b])
      return dp[a][b];
    bool ans = false;
    for (auto e : g[a])
      if (ans = (e == b || dfs(g, dp, e, b)))
        break;
    return dp[a][b] = ans;
  }

public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<vector<int>> g(n);
    for (auto &v : prerequisites)
      g[v[0]].push_back(v[1]);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<bool> ans;
    for (auto &q : queries)
      ans.push_back(dfs(g, dp, q[0], q[1]));
    return ans;
  }
};
