class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    int ans = 0;
    vector<vector<int>> g(n);
    for (auto &v : edges) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    dfs(g, hasApple, ans, 0);
    return ans * 2;
  }

  bool dfs(vector<vector<int>> &g, vector<bool> &hasApple, int &ans, int i,
           int parent = -1) {
    bool apple = hasApple[i];
    for (int j : g[i]) {
      if (j == parent)
        continue;
      if (dfs(g, hasApple, ans, j, i)) {
        ans++;
        apple = true;
      }
    }
    return apple;
  }
};
