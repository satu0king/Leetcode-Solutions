class Solution {
  double ans = 0;
  vector<vector<int>> g;

public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    g = vector<vector<int>>(n);
    for (auto &v : edges) {
      g[v[0] - 1].push_back(v[1] - 1);
      g[v[1] - 1].push_back(v[0] - 1);
    }
    g[0].push_back(-1);

    dfs(t, target - 1);

    return ans;
  }

  void dfs(int t, int target, int i = 0, double p = 1, int parent = -1) {
    if (t < 0)
      return;
    if (t == 0 && i == target)
      ans += p;

    else if (g[i].size() == 1 && i == target)
      ans += p;

    p /= max(1, (int)g[i].size() - 1);

    for (int v : g[i])
      if (v != parent)
        dfs(t - 1, target, v, p, i);
  }
};
