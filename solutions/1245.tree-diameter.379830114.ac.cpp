class Solution {
public:
  int treeDiameter(vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> g;
    for (auto e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    int ans = 0;
    dfs(g, edges[0][0], -1, ans);
    return ans;
  }

  int dfs(unordered_map<int, vector<int>> &g, int i, int parent, int &ans) {

    int maxDepth = 0;

    for (auto v : g[i]) {
      if (v == parent)
        continue;
      int s = dfs(g, v, i, ans);
      ans = max(ans, maxDepth + s);
      maxDepth = max(maxDepth, s);
    }

    return maxDepth + 1;
  }
};
