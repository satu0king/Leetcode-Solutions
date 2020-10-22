class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    vector<int> ans(n, -1);
    vector<vector<int>> g(n);

    for (auto xy : richer)
      g[xy[1]].push_back(xy[0]);

    for (int i = 0; i < n; i++)
      dfs(i, quiet, ans, g);
    return ans;
  }

  int dfs(int i, vector<int> &quiet, vector<int> &ans, vector<vector<int>> &g) {
    if (ans[i] == -1) {
      ans[i] = i;
      for (auto j : g[i])
        if (quiet[dfs(j, quiet, ans, g)] < quiet[ans[i]])
          ans[i] = dfs(j, quiet, ans, g);
    }
    return ans[i];
  };
};
